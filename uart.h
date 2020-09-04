/*
 * uart.h
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */

#ifndef UART_H_
#define UART_H_
#define FOSC 8000000
#define BAUD 9600

void init_uart();
void send_one_letter(unsigned char letter);
char receive_the_letter();
void ready_to_send();
void readt_to_receive();



#endif /* UART_H_ */
