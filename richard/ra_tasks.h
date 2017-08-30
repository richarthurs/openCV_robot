/*
 * ra_tasks.h
 *
 *  Created on: Aug 29, 2017
 *      Author: Richard
 */

#ifndef RICHARD_RA_TASKS_H_
#define RICHARD_RA_TASKS_H_

#include "sys_common.h"
#include "gio.h"
#include "FreeRTOS.h"
#include "os_task.h"
#include "system.h"
#include "os_queue.h"

xTaskHandle xBlinkyTask;
xTaskHandle xPrinterTask;

QueueHandle_t rxQueue; // to receive characters from UART

void raInit(void);
void vBlinky(void *pvParameters);
void vPrinter(void *pvParameters);


#endif /* RICHARD_RA_TASKS_H_ */
