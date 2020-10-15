#ifndef TASK_BOOT
#define TASK_BOOT

#include "global.h"

typedef enum {
    TB__SUSPEND_SELF,
    TB__SET_PINOUT,
    TB__RESUME_TASK_NETWORK,
} task_boot_state_t;

void vTaskBoot(void* pvParams);

#endif