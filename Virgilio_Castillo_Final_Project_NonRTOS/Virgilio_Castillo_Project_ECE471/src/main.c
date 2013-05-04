//Modified by Virgilio Castillo
//Base written Nathan Zimmerman

#include "lpc17xx.h" // processor includes
#include "stdint.h" // includes for uint8_t stuff
#include "stdio.h"
#include "W5200/tcp.h"
#include "LCD/lcd.h" // includes for ldc
#include "DRIVERS/adc.h"
#include "DEV/ece471.h"
#include <math.h>
#include "DRIVERS/ssp.h"
#include "TEMPSENSOR/TEMP.h"



static char buffer[40];

/*static TCP_CONFIG tcp_setup;
uint8 MAC[6] = {0x00, 0x08, 0xDC, 0x01, 0x02, 0x03};//MAC Address
uint8 IP[4] = {192, 168, 1, 23};//IP Address
uint8 GateWay[4] = {192, 168, 1, 1};//Gateway Address
uint8 SubNet[4] = {255, 255, 255, 0};//SubnetMask Address
uint8_t Dest_IP[4] = {192, 168, 1, 103}; //DST_IP Address


uint8_t get_command();
float adc_calc = 0;
bool startup =false;
*/
int main(void)
{  

	char mystring[20];
	delay_ms(100);//100ms Delay
	led_setup();//Initial Setup for LEDs
	LCD_SETUP(buffer);//LCD Setup
	TEMP_SPI_Init();//Initialize SPI for Temperature Sensor


	LPC_GPIO1 -> FIODIR |= LED0 + LED1 + LED2 + LED3 + LED4 + LED5 + LED6 + LED7; // Define LEDs as outputs
	LPC_GPIO1 -> FIOPIN |= LED0 + LED1 + LED2 + LED3 + LED4 + LED5 + LED6 + LED7; // Assert lines high, aka turn off leds

	/*
	tcp_setup.Gateway = GateWay;//Gateway Address
	tcp_setup.MAC = MAC;
	tcp_setup.Source_IP = IP;//IP Address
	tcp_setup.Source_Port= 80; // Web Port
	tcp_setup.Subnet= SubNet;//SubnetMask Address
	tcp_setup.s= 0;
	tcp_socket_init(&tcp_setup);
*/
	//Separate code from ethernet module and temp sensor to avoid conflict with data line

	write_to_eight_bit_reg(0x40,0x00);//Writing to 8-bit registers for config and command bytes

	while(1)
	{
		delay_ms(480);
		/*if(check_for_connections(&tcp_setup)) // Wait for connection)
		{
			process_request(&tcp_setup);
			tcp_socket_init(&tcp_setup);


		}*/


		//LPC_GPIO1 -> FIOPIN ^= LED0 + LED1 + LED2;
		while(!SW0_PRESSED);//Used for debugging
		uint8_t receiveddata = read_a_eight_bit_reg( (1<<6)+ (1<<4));
		delay_ms(1000);
		setColor16(ST7735_16_BLUE);
		sprintf(mystring,"Temp: %d", receiveddata);

		drawString8x12(10,50,mystring);

		//Using leds for delay of 240ms to make it look nice and debug at the same time

		LPC_GPIO1 -> FIOPIN ^= LED0;
		delay_ms(5);
		LPC_GPIO1 -> FIOPIN ^= LED1;
		delay_ms(15);
		LPC_GPIO1 -> FIOPIN ^= LED2;
		delay_ms(25);
		LPC_GPIO1 -> FIOPIN ^= LED3;
		delay_ms(35);
		LPC_GPIO1 -> FIOPIN ^= LED4;
		delay_ms(45);
		LPC_GPIO1 -> FIOPIN ^= LED5;
		delay_ms(55);
		LPC_GPIO1 -> FIOPIN ^= LED6;
		delay_ms(65);
		LPC_GPIO1 -> FIOPIN ^= LED7;

	}

}





