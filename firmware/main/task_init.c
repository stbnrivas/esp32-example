#include "task_init.h"


void vTaskInit(void* pvParams){
    uint32_t memory = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGI("ESP32_APP","memory init=%d",memory);
    task_init_state_t state = TI__SUSPEND_SELF;
    for(;;){
        switch(state){
            case TI__SUSPEND_SELF:
                ESP_LOGI("ESP32_APP","init: suspend");
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","init: state=%d",state);
                state = TI__INIT_A;
                break;
            case TI__INIT_A:
                ESP_LOGI("ESP32_APP","init: state=%d",state);
                vTaskDelay(500/portTICK_PERIOD_MS);
                state = TI__INIT_B;
                break;
            case TI__INIT_B:
                ESP_LOGI("ESP32_APP","init: state=%d",state);
                vTaskDelay(500/portTICK_PERIOD_MS);
                state = TI__RESUME_TASK_NETWORK;
                break;
            case TI__RESUME_TASK_NETWORK:
                ESP_LOGI("ESP32_APP","init: state=%d",state);
                vTaskResume(task_boot_loop);
                //vTaskResume(task_network_loop);
                state = TI__SUSPEND_SELF;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task_init invalid state=%d",state);
                break;
        }
    }
    vTaskDelete(NULL);
}