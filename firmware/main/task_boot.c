#include "task_boot.h"


void vTaskBoot(void* pvParams){
    task_boot_state_t state = TB__SET_PINOUT;
    for(;;){
        switch(state){
            case TB__SUSPEND_SELF:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                vTaskSuspend(NULL);
                state = TB__SET_PINOUT;
                break;
            case TB__SET_PINOUT:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                state = TB__RESUME_TASK_NETWORK;
                break;
            case TB__RESUME_TASK_NETWORK:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                state = TB__SUSPEND_SELF;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task_boot invalid state=%d",state);
                break;
        }
    }
    vTaskDelete(NULL);
}