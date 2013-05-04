/*
 * TEMP.h
 *
 *  Created on: Apr 25, 2013
 *      Author: ReYCangri
 */

#ifndef TEMP_H_
#define TEMP_H_


#include <stdint.h>
#include <stdio.h>
#include "lpc17xx.h"
#include "../W5200/Types.h"
#include "../TEMPSENSOR/TempSensorSetup.h"



#define		TEMPSensor_CS		P0_25	//Chip Select

#define LOW 0
#define HIGH 1

/*********************************************************
* iinchip access function
*********************************************************/
//uint8 TEMPCHIP_READ(uint16 addr);
//uint8 TEMPCHIP_WRITE(uint16 addr,uint8 data);
uint8_t read_a_eight_bit_reg(uint8_t command);
uint16_t read_a_sixteen_bit_reg(uint8_t command);
void write_to_sixteen_bit_reg(uint8_t command, uint16_t data);
void write_to_eight_bit_reg(uint8_t command, uint8_t data);
void GPIO_Config(void);
void tempchip_init(void); // reset iinchip

#endif /* TEMP_H_ */
