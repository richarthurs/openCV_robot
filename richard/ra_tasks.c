/*
 * ra_tasks.c
 *
 *  Created on: Aug 29, 2017
 *      Author: Richard
 */

#include "ra_tasks.h"
#include "ra_serial.h"

void raInit(){
    if (xTaskCreate(vBlinky,"Blinky", configMINIMAL_STACK_SIZE, NULL, 1, &xBlinkyTask) != pdTRUE){
        /* Task could not be created */
        while(1);
    }

    if (xTaskCreate(vPrinter,"Printer", 900, NULL, 2, &xPrinterTask) != pdTRUE){
        /* Task could not be created */
        while(1);
    }

    rxQueue = xQueueCreate( 10, sizeof( char*) );

}



void vBlinky(void *pvParameters){
    for(;;){
        gioSetBit(gioPORTB, 2, gioGetBit(gioPORTB, 2) ^ 1); // Toggles the A2 bit
        vTaskDelay( pdMS_TO_TICKS( 500 ));
    }
}

void vPrinter(void *pvParameters){
    char printme;
    const TickType_t xTicksToWait = pdMS_TO_TICKS(10);

    for(;;){
        while (xQueueReceive(rxQueue, &printme, xTicksToWait) == pdPASS) {
            serialSendln(&printme);
            sciReceive(scilinREG, 1, &currChar);
        }

    }
}
