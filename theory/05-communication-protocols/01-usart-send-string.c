#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

void usart_init(void);
void usart_send(unsigned char data);

int main(void)
{
    unsigned char stri[] = "AVR Serial";
    unsigned char i = 0;

    usart_init();

    while (1)
    {
        usart_send(stri[i]);
        i++;

        if (stri[i] == '\0')
        {
            i = 0;
        }

        _delay_ms(100);   // optional for visible spacing
    }

    return 0;
}

void usart_init(void)
{
    UCSRB = (1 << TXEN);  
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRL = 0x33;   // 9600 baud at 8MHz
}

void usart_send(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}