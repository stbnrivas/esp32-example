#ifndef TASK_UPDATE_SENDER_H
#define TASK_UPDATE_SENDER_H

#include "global.h"
#include "task_update_receiver.h"

typedef enum {
    TUS__SUSPEND_SELF,
    TUS__SUSPEND_UPDATE_RECV,
    TUS__UPDATE_SELF_REQ,
    TUS__UPDATE_SELF_RES,
    TUS__SEND_UPDATE_REQ,
    TUS__SEND_UPDATE_RES,
    TUS__SEND_UPDATE_ACK,
    TUS__EXCEED_RETRY_REBOOT,
    TUS__RESUME_UPDATE_RECV,
    TUS__WAIT_FOR_NEXT_UPDATE
} task_update_sender_state_t;

void vTaskUpdateSender(void* pvParams);


#endif