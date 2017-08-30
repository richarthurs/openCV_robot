/*
 * ra_serial.h
 *
 *  Created on: Aug 29, 2017
 *      Author: Richard
 */

#ifndef RICHARD_RA_SERIAL_H_
#define RICHARD_RA_SERIAL_H_
#include "sci.h"

void raSerialInit(void);

void serialSendln(const char*);
void sciNotification(sciBASE_t *sci, uint32 flags);

extern unsigned char currChar;


#endif /* RICHARD_RA_SERIAL_H_ */
