/*
 * main.c
 *
 *  Author: Mahmoud Ayoub
 */
#include "UART.h"

int main () {
    SWUART_init(9600) ; 
    while (1) 
    {
        SWUART_recieve(&data) ; 
        SWUART_send(data) ; 
    }

    return 0 ; 
}