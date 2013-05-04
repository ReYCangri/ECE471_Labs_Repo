/*
 * TempSensorSetup.c
 *
 *  Created on: Apr 25, 2013
 *      Author: ReYCangri
 */
#ifndef __TempSensorSetup_H
#define __TempSensorSetup_H

#include <stdint.h>
#include <stdio.h>


void TEMP_SPI_Init(void);
void TEMP_CS(uint8_t val);

//void SPI1_TXByte(uint8_t byte);

#endif
