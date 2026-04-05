#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

char str[] = "serial transmission";
volatile unsigned char i = 0;  // Global index for ISR

// USART initialization
void usart_init(void)
{
    UCSRB = (1 << TXEN) | (1 << TXCIE);   // Enable TX + TX complete interrupt
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); // 8-bit data
    UBRRL = 51;   // 9600 baud for 8MHz
}

int main(void)
{
    usart_init();
    sei();           // Enable global interrupts

    UDR = str[i++];  // Start first transmission

    while (1)
    {
        // Main loop can do other tasks while ISR handles string transmission
    }

    return 0;
}

// ISR triggered after each character is transmitted
ISR(USART_TXC_vect)
{
    if (str[i] != '\0')   // If more characters remain
    {
        UDR = str[i++];
    }
    else                  // If end of string reached, restart
    {
        i = 0;
        UDR = str[i++];
    }
}