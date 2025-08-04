#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

void UART_init(unsigned long USART_BAUDRATE)
{
    unsigned int BAUD_PRESCALE = ((F_CPU / (USART_BAUDRATE * 16UL)) - 1);

    // Set baud rate
    UBRR0L = (uint8_t)BAUD_PRESCALE;
    UBRR0H = (uint8_t)(BAUD_PRESCALE >> 8);

    // Enable transmitter and receiver
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Set frame format: 8 data bits, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

unsigned char UART_RxChar()
{
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void UART_TxChar(char ch)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = ch;
}

void UART_SendString(char *str)
{
    while (*str)
    {
        UART_TxChar(*str++);
    }
}

int main()
{
    char c;
    UART_init(9600);

    UART_SendString("\n\rEcho Test Ready:\n\r");

    while (1)
    {
        c = UART_RxChar();     // Wait and receive
        UART_TxChar(c+1);        // Echo it back
    	UART_TxChar('\n'); 
    }

    return 0;
}

