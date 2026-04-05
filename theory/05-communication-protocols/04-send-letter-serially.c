#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

void usart_init(void)
{
    UCSRB = (1 << TXEN) | (1 << TXCIE);   // Enable transmitter + TX interrupt
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); // 8-bit data
    UBRRL = 0x33;   // 9600 baud for 8MHz
}

int main(void)
{
    usart_init();
    sei();          // Enable global interrupt

    UDR = 'A';   // Start transmission by writing the first character to UDR

    while (1);

    return 0;
}

ISR(USART_TXC_vect)
{
    UDR = 'A';   
}