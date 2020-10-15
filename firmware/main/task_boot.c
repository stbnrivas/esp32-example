#include "task_boot.h"


void vTaskBoot(void* pvParams){
    uint32_t memory = uxTaskGetStackHighWaterMark(NULL);;
    ESP_LOGI("ESP32_APP","memory boot=%d",memory);
    task_boot_state_t state = TB__SET_PINOUT;
    for(;;){
        switch(state){
            case TB__SUSPEND_SELF:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","resume task boot");
                state = TB__SET_PINOUT;
                break;
            case TB__SET_PINOUT:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                state = TB__RESUME_TASK_INIT;
                break;
            case TB__RESUME_TASK_INIT:
                ESP_LOGI("ESP32_APP","boot: state=%d",state);
                //vTaskResume(task_init);
                state = TB__SUSPEND_SELF;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task_boot invalid state=%d",state);
                break;
        }
    }
    vTaskDelete(NULL);
}