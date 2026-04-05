#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

void usart_init(void);

int main(void) {
    usart_init();

    while (1)
    {
        while (!(UCSRA & (1 << RXC)));
        _delay_ms(100);
        PORTA = UDR;        
    }

    return 0;  
}

void usart_init(void) {
    DDRA = 0xFF; // Set PORTA as output
    UCSRB = (1 << RXEN); // Enable receiver i.e. UCSRB = 0b00010000 = 0x10
    UCSRC |= (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL); //UCSRC = 0b10000110 = 0x86
    UBRRL = 0x33; // Set baud rate to 9600 for 8MHz clock frequency i.e. UBRRL = 0x33 = 51
}