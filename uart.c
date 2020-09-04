/*
 * uart.c
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"


void init_uart()
{
	unsigned int rate=0;
	    UCSRB = (1 << RXEN) | (1 << TXEN);
		UCSRC = (1 << URSEL) | (3 << UCSZ0);
		rate= FOSC/16/BAUD-1;
		UBRRL=rate;
		UBRRH=(rate<<8);


}
void ready_to_send()
{
	while (!( UCSRA & (1<<UDRE))) ;
	LCD_go_to(1,1);
	LCD_Send_string(" uart is ready ");
	_delay_ms(3000);
	clear_lcd ();


}
void readt_to_receive()
{
	while (!(UCSRA & (1<<RXC)));
	LCD_go_to(1,1);
	LCD_Send_string(" Receiving complete ! ");
	_delay_ms(3000);
		clear_lcd ();

}
void send_one_letter(unsigned char letter)
{
	 ready_to_send();
	 UDR=letter;

}
char receive_the_letter()
{
	readt_to_receive();
	return UDR ;
}
void UART_SEND_string(char *array)
{

	while(*array !='\0')
	{

		send_one_letter(*array++);

	}

}
