#ifndef TASK_INIT
#define TASK_INIT

#include "global.h"

typedef enum {
    TI__SUSPEND_SELF,
    TI__INIT_A,
    TI__INIT_B,
    TI__RESUME_TASK_NETWORK,
} task_init_state_t;

void vTaskInit(void* pvParams);

#endif