/*
 * main.c
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */
#include<avr/io.h>
#include<util/delay.h>

int main()
{
	while(1)
	{
	LCD_init();
	init_uart();
	 UART_SEND_string("ALI MOHAMED ELSIAD ");

	 _delay_ms(1000);
	 receive_the_letter();
	}



	return 0;
}

