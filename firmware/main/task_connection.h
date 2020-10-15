#ifndef TASK_CONNECTION_H
#define TASK_CONNECTION_H

#include "global.h"

typedef enum {
    TC__SUSPEND_SELF,
    TC__SEND,
    TC__WAIT_ACK,
    TC__EXCEED_RETRY_REBOOT,
    TC__RESUME_TASK_BOOT,
} task_connection_state_t;

void vTaskConnection(void* pvParams);


#endif