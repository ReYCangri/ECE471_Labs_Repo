#include "lpc17xx.h"
#include <string.h>
#include <stdlib.h>
#include "../DRIVERS/ssp.h"
#include "../TEMPSENSOR/TEMP.h"
#include "../TEMPSENSOR/TempSensorSetup.h"

void TEMP_SPI_Init(void)
{
	LPC_GPIO0 -> FIODIR |= (1 << 25);//Set up P0.25 as output to use for Chip Select
	SSP0Init();
}

// Connected to Data Flash
void TEMP_CS(uint8_t val)
{
	if (val == LOW) {
   		LPC_GPIO0->FIOCLR = (1<<25);
	}else if (val == HIGH){
   		LPC_GPIO0->FIOSET = (1<<25);
	}
}



/*
void SPI1_TXByte(uint8_t byte)
{
	  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

	  SPI_I2S_SendData(SPI1, byte);
}*/

