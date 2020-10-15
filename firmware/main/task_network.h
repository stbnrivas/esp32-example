#ifndef TASK_NETWORK_H
#define TASK_NETWORK_H

#include "global.h"

typedef enum {
    TN__SUSPEND_SELF,
    TN__CHECK_NETWORK,
    TN__EXCEED_RETRY_REBOOT,
    TN__RESUME_TASK_CONNECTION,
} task_network_state_t;

void vTaskNetwork(void* pvParams);

#endif