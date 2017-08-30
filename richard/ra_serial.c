/*
 * ra_serial.c
 *
 *  Created on: Aug 29, 2017
 *      Author: Richard
 */

#ifndef RICHARD_RA_SERIAL_C_
#define RICHARD_RA_SERIAL_C_
#include "sci.h"
#include "sys_common.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ra_tasks.h"

unsigned char currChar = '\0';

void serialSendln(const char* stringToSend){
    sciSend(scilinREG, strlen(stringToSend), (unsigned char *)stringToSend);
    sciSend(scilinREG, 2, "\r\n");
    sciReceive(scilinREG, 1, &currChar); // place into receive mode
}

void raSerialInit(){
    sciInit();
    sciEnableNotification(scilinREG, SCI_RX_INT);
    serialSendln("Serial started.");
    sciReceive(scilinREG, 1, &currChar); // place into receive mode
}

void sciNotification(sciBASE_t *sci, uint32 flags){
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xQueueSendToBackFromISR(rxQueue, &currChar, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        sciReceive(scilinREG, 1, (unsigned char *)&currChar); // place into receive mode
}

#endif /* RICHARD_RA_SERIAL_C_ */
