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
TaskHandle_t task_network_loop;
TaskHandle_t task_connection_loop;

TaskHandle_t task_update_sender_loop;
TaskHandle_t task_update_receiver_loop;

#define DELAY 500


#endif