#include "task_network.h"


void vTaskNetwork(void* pvParams){
    task_network_state_t state = TN__SUSPEND_SELF;
    uint32_t memory = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGI("ESP32_APP","memory network=%d",memory);
    for(;;){
        switch(state){
            case TN__SUSPEND_SELF:
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","network: state=%d",state);
                state = TN__CHECK_NETWORK;
                break;
            case TN__CHECK_NETWORK:
                ESP_LOGI("ESP32_APP","network: state=%d",state);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                state = TN__EXCEED_RETRY_REBOOT;
                break;
            case TN__EXCEED_RETRY_REBOOT:
                ESP_LOGI("ESP32_APP","network: state=%d",state);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                state = TN__RESUME_TASK_CONNECTION;
                break;
            case TN__RESUME_TASK_CONNECTION:
                ESP_LOGI("ESP32_APP","network: state=%d",state);
                vTaskResume(task_boot_loop);
                state = TN__SUSPEND_SELF;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task_network invalid state=%d",state);
                break;
        }
    }
    vTaskDelete(NULL);
}