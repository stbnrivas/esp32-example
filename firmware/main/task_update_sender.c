#include "task_update_sender.h"



void vTaskUpdateSender(void* pvParams){
    task_update_sender_state_t state = TUS__SUSPEND_SELF;
    for(;;){
        switch(state){
            case TUS__SUSPEND_SELF:
                vTaskSuspend(NULL);
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__SUSPEND_UPDATE_RECV;
                break;
            case TUS__SUSPEND_UPDATE_RECV:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__UPDATE_SELF_REQ;
                break;
            case TUS__UPDATE_SELF_REQ:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__UPDATE_SELF_RES;
                break;
            case TUS__UPDATE_SELF_RES:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__SEND_UPDATE_REQ;
                break;
            case TUS__SEND_UPDATE_REQ:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__SEND_UPDATE_RES;
                break;
            case TUS__SEND_UPDATE_RES:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__SEND_UPDATE_ACK;
                break;
            case TUS__SEND_UPDATE_ACK:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__EXCEED_RETRY_REBOOT;
                break;
            case TUS__EXCEED_RETRY_REBOOT:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__RESUME_UPDATE_RECV;
                break;
            case TUS__RESUME_UPDATE_RECV:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);
                state = TUS__WAIT_FOR_NEXT_UPDATE;
                break;
            case TUS__WAIT_FOR_NEXT_UPDATE:
                ESP_LOGI("ESP32_APP","update_sender: state=%d",state);
                vTaskDelay(DELAY/portTICK_PERIOD_MS);


                ESP_LOGI("ESP32_APP","update_sender: resume receiver");
                vTaskResume(task_update_receiver_loop);
                vTaskDelay(5000/portTICK_PERIOD_MS);
                while(!taskUpdateSenderIddle()){
                    //TODO:
                    vTaskDelay(10/portTICK_PERIOD_MS);
                }
                vTaskSuspend(task_update_receiver_loop);
                ESP_LOGI("ESP32_APP","update_sender: suspend receiver");


                state = TUS__SUSPEND_UPDATE_RECV;
                break;

        }
    }
}

