/*
 * ra_tasks.c
 *
 *  Created on: Aug 29, 2017
 *      Author: Richard
 */

#include "ra_tasks.h"
#include "ra_serial.h"

void raInit(){

    if (xTaskCreate(vBlinky,"Blinky", configMINIMAL_STACK_SIZE, NULL, 2, &xBlinkyTask) != pdTRUE){
        /* Task could not be created */
        while(1);
    }
}



void vBlinky(void *pvParameters){
    for(;;){
        gioSetBit(gioPORTB, 2, gioGetBit(gioPORTB, 2) ^ 1); // Toggles the A2 bit
        serialSendln("blink");
        vTaskDelay( pdMS_TO_TICKS( 500 ));
    }
}
