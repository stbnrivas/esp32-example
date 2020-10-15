#ifndef GLOBAL_H
#define GLOBAL_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_log.h"



#define BUF_SIZE (1024)

uint8_t buf_rx[BUF_SIZE];
char buf_tx[BUF_SIZE];

TaskHandle_t task_boot_loop;
TaskHandle_t task_init_loop;


#endif