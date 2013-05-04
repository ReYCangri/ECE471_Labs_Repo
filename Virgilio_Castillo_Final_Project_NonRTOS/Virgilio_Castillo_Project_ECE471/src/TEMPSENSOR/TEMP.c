/*
 * TEMP.c
 *
 *  Created on: Apr 25, 2013
 *      Author: ReYCangri
 */

#include "lpc17xx.h"
#include <stdio.h>
#include <string.h>
#include "../DRIVERS/ssp.h"
#include "../TEMPSENSOR/TEMP.h"
#include "../DEV/ece471.h"



void GPIO_Config(void)
{
	LPC_GPIO0 ->FIODIR |= TEMPSensor_CS; // P0.25 -> nCS, P0.23 and P0.24 -> could be setup for INT or CT
	//SCLK (pin 1) --> P0.15
	//DIN (pin 3) --> P0.18
	//DOUT (pin 2) --> P0.17
	//nCS (pin 4) --> P0.25
	LPC_GPIO0 -> FIOSET = TEMPSensor_CS; // CS HIGH as devices are disabled when high
}


void Reset_TempAlarm(void)//reset temperature registers INT and CT
{
//Send right value to DIN for reset 0x01;
}

void TEMPCHIP_CSoff(void)
{
	TEMP_CS(LOW);
}
void TEMPCHIP_CSon(void)
{
	TEMP_CS(HIGH);
}


uint8  TEMPCHIP_SpiSendData(uint8 dat)//Function to send data to SPI
{
	return(SSP0Send(dat));

}

/**
@brief	This function writes the data into W5200 registers.
*/



void write_to_eight_bit_reg(uint8_t command, uint8_t data)
{
	TEMPCHIP_CSoff();                            // CS=0, SPI start
	SSP0Send((command));  // Send Command Byte
	SSP0Send(data);                  // // Send data byte that you wish to write
	TEMPCHIP_CSon();                             // CS=1,  SPI end

}

void write_to_sixteen_bit_reg(uint8_t command, uint16_t data)
{
	TEMPCHIP_CSoff();                            // CS=0, SPI start
	SSP0Send(command);  // Send Command Byte
	SSP0Send(data>>8 );                  // // Send data byte that you wish to write
	SSP0Send(data);                  // // Send data byte that you wish to write
	TEMPCHIP_CSon();                             // CS=1,  SPI end

}

uint16_t read_a_sixteen_bit_reg(uint8_t command)//removed (uint16_t data) parameter
{
	uint16_t local_data=0;
	TEMPCHIP_CSoff();                            // CS=0, SPI start
	SSP0Send(command);  // Send Command Byte
	local_data = SSP0Send(0xFF) <<8;                  // // Send data byte that you wish to write
	local_data = local_data + SSP0Send(0xFF);                  // // Send data byte that you wish to write
	TEMPCHIP_CSon();
	// CS=1,  SPI end
	return local_data;
}

uint8_t read_a_eight_bit_reg(uint8_t command)
{

	uint16_t local_data = 0;
	TEMPCHIP_CSoff();
	SSP0Send(command);
	local_data = SSP0Send(0xFF);//From datasheet, We want High this whole time
	TEMPCHIP_CSon();
	return local_data;
}

/*
uint8 TEMPCHIP_WRITE(uint16 addr,uint8 data)
{
	TEMPCHIP_ISR_DISABLE();                      // Interrupt Service Routine Disable

		//SPI MODE I/F
		TEMPCHIP_CSoff();                            // CS=0, SPI start

		TEMPCHIP_SpiSendData((addr & 0xFF00));  // Send Command Byte
		TEMPCHIP_SpiSendData(0x80);                  // Send Data byte, sent data is arbitrary
		TEMPCHIP_SpiSendData(0x01);                  // Write data length 2

		TEMPCHIP_CSon();                             // CS=1,  SPI end

	    TEMPCHIP_ISR_ENABLE();                       // Interrupt Service Routine Enable
		return 1;
}

//@brief	This function reads the value from W5200 registers.

uint8 TEMPCHIP_READ(uint16 addr)
{
	uint8 data;

	TEMPCHIP_ISR_DISABLE();                       // Interrupt Service Routine Disable

	TEMPCHIP_CSoff();                             // CS=0, SPI start

    TEMPCHIP_SpiSendData((addr & 0xFF00) >> 8);   // Address byte 1
	TEMPCHIP_SpiSendData(addr & 0x00FF);          // Address byte 2
	TEMPCHIP_SpiSendData(0x00);                   // Data read command and Read data length 1
	TEMPCHIP_SpiSendData(0x01);                   // Read data length 2
	data = TEMPCHIP_SpiSendData(0x00);            // Data read (read 1byte data)

    TEMPCHIP_CSon();                              // CS=1,  SPI end

    TEMPCHIP_ISR_ENABLE();                        // Interrupt Service Routine Enable
	return (data);
}*/
