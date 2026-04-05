#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void usart_init(void) {
    DDRB = 0xFF; // Set PORTB as output
    UCSRB = (1 << RXEN) | (1 << RXCIE); // Enable receiver and receive complete interrupt
    UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL); //UCSRC = 0b10000110 = 0x86
    UBRRL = 0x33; // Set baud rate to 9600 for 8MHz clock frequency i.e. UBRRL = 0x33 = 51
}

int main(void) {
    usart_init();
    sei(); // Enable global interrupts

    while (1)
    {
        // Main loop can perform other tasks while waiting for USART interrupts
    }

    return 0;  
}

ISR(USART_RXC_vect) {
    _delay_ms(100); // Optional delay to ensure data is fully received
    PORTB = UDR; // Read the received data from USART Data Register and output it to PORTB
}