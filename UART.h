/*
 * UART.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef UART_H_
#define UART_H_

#define UART_UDR		(*((volatile unsigned char*)0x2C))
#define UART_UCSRA		(*((volatile unsigned char*)0x2B))
#define UART_UCSRB		(*((volatile unsigned char*)0x2A))
#define UART_UCSRC		(*((volatile unsigned char*)0x40))
#define UART_UBRRH		(*((volatile unsigned char*)0x40))
#define UART_UBRRL		(*((volatile unsigned char*)0x29))

#define F_CPU 8000000UL			/* Define frequency here its 8MHz */


void SWUART_init(uint32_t baudrate);
void SWUART_send(uint8_t data);
void SWUART_recieve(uint8_t *data); 

#endif /* UART_H_ */