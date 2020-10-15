#include "task_update_receiver.h"

task_update_receiver_state_t _state;

bool taskUpdateSenderIddle(void){
    return _state == TUR__WAIT_FOR_RECV;
}


void vTaskUpdateReceiver(void* pvParams){
    _state = TUR__SUSPEND_SELF;
    uint32_t memory = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGI("ESP32_APP","memory network=%d",memory);
    for(;;){
        switch(_state){
            case TUR__SUSPEND_SELF:
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","update_receiver: _state=%d",_state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                _state = TUR__WAIT_FOR_RECV;
                break;
            case TUR__WAIT_FOR_RECV:
                ESP_LOGI("ESP32_APP","update_receiver: _state=%d",_state);
                ulTaskNotifyTake(pdFALSE,portMAX_DELAY-1);
                _state = TUR__PARSE;
                break;
            case TUR__PARSE:
                ESP_LOGI("ESP32_APP","update_receiver: _state=%d",_state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                _state = TUR__DOING;
                break;
            case TUR__DOING:
                ESP_LOGI("ESP32_APP","update_receiver: _state=%d",_state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                _state = TUR__WAIT_FOR_RECV;
                break;
            default:
                ESP_LOGE("ESP32_APP","ERROR into task update receiver invalid _state=%d",_state);
                break;
        }
    }
}

