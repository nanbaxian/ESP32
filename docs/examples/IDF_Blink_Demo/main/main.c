/*
  ESP-IDF Blink Demo for the ESP32-S3 Super Mini

  Blinks the onboard blue LED on GPIO48 once per second.
  The LED is inverted: driving GPIO48 LOW turns it on.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_GPIO GPIO_NUM_48
#define TAG      "blink"

void app_main(void)
{
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Blink started on GPIO%d", LED_GPIO);

    int level = 0;
    while (1) {
        // Inverted LED: 0 = on, 1 = off
        gpio_set_level(LED_GPIO, level);
        ESP_LOGI(TAG, "LED %s", level == 0 ? "ON" : "OFF");

        level = !level;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
