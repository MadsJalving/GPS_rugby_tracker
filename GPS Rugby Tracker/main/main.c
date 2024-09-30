#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_chip_info.h"

void app_main(void)
{
    printf("Hello world, from ESP32-S3!\r\n");
    
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    printf("This is an ESP32-S3 chip with %d CPU cores, WiFi%s%s, ",
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    printf("silicon revision %d, ", chip_info.revision);
    
    // Main loop
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
    }
}