/*
 * UART.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "UART.h"

/*
Description : The function initializes UART module with the specified baud rate , data frame
inputs		: baud rate
outputs		: none
*/
void SWUART_init(uint32_t baudrate) {
	/* Turn on transmission and reception */
	UART_UCSRB |= (1 << 4) | (1 << 3) ; 
	
	/*  setting frame format (2 stop bits , 8 bits data size) */
	UART_UCSRC = 0b10001110 ;
				
	
	unsigned int baud_prescale ; 
	baud_prescale = ((F_CPU / (16UL*baud_rate))-1) ; 
	UART_UBRRL = baud_prescale ; 
	UART_UBRRH = baud_prescale >> 8 ; 
}
/*
Description : The function waits for the transmit buffer to be empty by checking the UDRE Flag, before loading it with new data to be transmitted.
inputs		: data to be transmitted
outputs		: none
*/
void SWUART_send(uint8_t data) {
	/*
	 (UDRE) Flag indicates whether the transmit buffer is ready to receive new data. 
	 This bit is set when the transmit buffer is empty, and cleared when the transmit buffer
	 contains data to be transmitted that has not yet been moved into the Shift Register
	*/
 	while ( (UART_UCSRA & (1<<5)) == 0) ;	/* Wait for empty transmit buffer*/
 	UART_UDR = data ;
}

/*
Description : The function waits for data to be present in the receive buffer by checking the RXC Flag, 
			   before reading the buffer and returning the value
inputs		: none
outputs		: received data
*/
void SWUART_recieve(uint8_t *data) {
	while ( (UART_UCSRA & (1<<7)) == 0) ;	/* Wait till data is received */
	return UART_UDR ; 
}