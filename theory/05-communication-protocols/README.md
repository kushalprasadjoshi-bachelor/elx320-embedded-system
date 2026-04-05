# Serial Communication in AVR Programs

This README lists all programs in this folder  which are related to the **Serial Communication in AVR**.

---

**1. AVR C Code to send string "AVR serial" that continously using USART with baud rate fo 9600.**

Configurations:
```
UBRRL = 0x33
UCSRA = 0X00
UCSRB = 0X08
UCSRC = 0X06
```

**Steps:**  
1. Load UCSRB with 0x08 to enable transmitter.  
2. Load UCSRC with 0x86.  
3. Load UBRRL with 0x 33 for 9600 baud rate at 8MHz frequency.  
4. Load UDR with required byte to transmit.  
5. Monitor UDRE bit of UCSRA to make sure UDR is empty and ready for next byte.  
6. To transmit the next character goto step 4.

```c
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
```

---

**2. Write a program to receive data serially using USART baud rate 9600 by polling RXC bit.**

Configurations:
```
UBRRL = 0x33
UCSRA = 0b00000000 = 0x00
UCSRB = 0b00010000 = 0x10
UCSRC = 0b10000110 = 0x86
```

```c
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
```

---

**3. Write a program to receive data serially using USART baud rate 9600 by interrupt.**

|USART interrupt vector name | Description |
|----------------------------|-------------|
| USART_RXC_vect | USART receive complete |
| USART_UDRE-vect | USART data register empty |
| USART_TXC_vect | USART transmit complete |

```c
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
```

---

**4. WAP to send letter 'A' serially using interrupt.**

```c
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
```

---

**5. Program to send string "serial transmission" using interrupt.**

```c
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
```

---