#include "task_connection.h"


void vTaskConnection(void* pvParams){
    task_connection_state_t state = TC__SUSPEND_SELF;
    uint32_t memory = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGI("ESP32_APP","memory connection=%d",memory);
    for(;;){
        switch(state){
            case TC__SUSPEND_SELF:
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","connection: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TC__SEND;
                break;
            case TC__SEND:
                ESP_LOGI("ESP32_APP","connection: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TC__WAIT_ACK;
                break;
            case TC__WAIT_ACK:
                ESP_LOGI("ESP32_APP","connection: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TC__EXCEED_RETRY_REBOOT;
                break;
            case TC__EXCEED_RETRY_REBOOT:
                ESP_LOGI("ESP32_APP","connection: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TC__RESUME_TASK_BOOT;
                break;
            case TC__RESUME_TASK_BOOT:
                ESP_LOGI("ESP32_APP","connection: state=%d",state);
                ESP_LOGI("ESP32_APP","connection: resuming boot");
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                vTaskResume(task_boot_loop);
                state = TC__SUSPEND_SELF;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task_connect invalid state=%d",state);
                break;
        }
    }
    vTaskDelete(NULL);
}