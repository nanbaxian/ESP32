# ESP-IDF Blink Demo

A minimal **ESP-IDF** project for the ESP32-S3 Super Mini. It blinks the onboard blue LED on gpio48 once per second and logs each state change over the USB serial port.

This is the ESP-IDF version of the [Blink Project](../Blink/README.md), which uses Arduino.

## Project Layout

```
IDF_Blink_Demo/
├── CMakeLists.txt        # Top-level project file (required by ESP-IDF)
├── README.md
└── main/
    ├── CMakeLists.txt    # Registers main.c as a component
    └── main.c            # Application code
```

## Requirements

- ESP-IDF v5.x or later (this project was written against the v6.1 setup used in the repo's VS Code settings)
- VS Code with the **Espressif IDF** extension, or a terminal with the ESP-IDF environment exported
- ESP32-S3 Super Mini and a USB-C data cable

## Code Explanation

- `gpio_reset_pin()` and `gpio_set_direction()` configure gpio48 as an output.
- The LED is inverted, so `gpio_set_level(LED_GPIO, 0)` turns it on.
- `vTaskDelay(pdMS_TO_TICKS(1000))` waits one second between toggles.
- `ESP_LOGI()` prints the state to the serial monitor.

## Instructions

### Option A: VS Code (ESP-IDF extension)

1. In VS Code, choose **File > Open Folder** and select `docs/examples/IDF_Blink_Demo`. The extension only detects a project in the folder you open, so do not open the repository root.
2. Click **Yes** when the extension asks to use this folder as an ESP-IDF project.
3. Run **ESP-IDF: Set Espressif Device Target** and select `esp32S3`.
4. Click **Build**, then **Flash**, then **Monitor**.

### Option B: Terminal

```bash
cd docs/examples/IDF_Blink_Demo
idf.py set-target esp32S3
idf.py build
idf.py -p <YOUR_PORT> flash monitor
```

Replace `<YOUR_PORT>` with your serial port, for example `COM3` on Windows or `/dev/ttyACM0` on Linux.

## Expected Output

```
I (xxx) blink: Blink started on gpio48
I (xxx) blink: LED ON
I (xxx) blink: LED OFF
```

The blue LED should blink once per second.

## Notes

- If the extension still reports "No standard ESP-IDF project was found", check that you opened `IDF_Blink_Demo` itself and not the repository root or the `Blink` folder.
- Holding BOOT (GPIO9) while pressing reset puts the board into download mode, as described in the [main guide](../../../README.md).
