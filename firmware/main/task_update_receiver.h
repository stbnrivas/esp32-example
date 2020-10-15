#ifndef TASK_UPDATE_RECEIVER
#define TASK_UPDATE_RECEIVER

#include "global.h"

typedef enum {
    TUR__SUSPEND_SELF,
    TUR__WAIT_FOR_RECV,
    TUR__PARSE,
    TUR__DOING,
} task_update_receiver_state_t;

bool taskUpdateSenderIddle(void);

void vTaskUpdateReceiver(void* pvParams);


#endif