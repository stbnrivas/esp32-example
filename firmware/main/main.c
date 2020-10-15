/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "global.h"
#include "task_boot.h"


void app_main(){
    esp_log_level_set("ESP32_APP",ESP_LOG_INFO);
	ESP_LOGI("ESP32_APP","booting");


    xTaskCreate(&vTaskBoot, "task_boot", 1024*2, NULL, 1, &task_boot_loop);

}
