# Programming for Embedded Systems Programs

This README lists all programs in this folder with cleaned code and a direct source link.

## 1. **Mirror input from PORTA to PORTB**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRA = 0x00;

    DDRB = 0xFF;

    while (1) {

        uint8_t a = PINA;

        PORTB = a;

    }

    return 0;

}
```

For more description of program visit this [01-input-output.c](./01-input-output.c).

---

## 2. **Output values from 0x00 to 0xFF on PORTC**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRC = 0xFF;

    for (uint16_t p = 0; p < 256; p++) {

        PORTC = p;

    }

    return 0;

}
```

For more description of program visit this [02-looping-output.c](./02-looping-output.c).

---

## 3. **Control two LEDs on PORTB using input from PORTD**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRD = 0x00;

    DDRB = 0xFF;

    while (1)
    {

        uint8_t portD_input = PIND;

        uint8_t masked_input = portD_input & 0x48;

        PORTB = masked_input;
    }

    return 0;

}
```

For more description of program visit this [03-control-leds.c](./03-control-leds.c).

---

## 4. **Toggle the 6th pin (PC5) of PORTC**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRC |= (1 << PC5);

    while (1) {

        PORTC ^= (1 << PC5);

    }

    return 0;

}
```

For more description of program visit this [04-toggle-a-pin.c](./04-toggle-a-pin.c).

---

## 5. **Turn ON 2nd pin (PD1) and OFF 5th pin (PD4) of PORTD**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRD |= (1 << PD1) | (1 << PD4);

    while (1) {

        PORTD |= (1 << PD1);

        PORTD &= ~(1 << PD4);

    }

    return 0;

}
```

For more description of program visit this [05-on-off-different-pins-of-same-port.c](./05-on-off-different-pins-of-same-port.c).

---

## 6. **Sum two numbers from PORTA and PORTB, control LED on PC3**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRA = 0x00;

    DDRB = 0x00;

    DDRC |= (1 << PC3);

    while (1)
    {

        int8_t portA_input = PINA;

        int8_t portB_input = PINB;

        int16_t sum = portA_input + portB_input;

        if (sum < 0)
        {

            PORTC |= (1 << PC3);
        }
        else
        {

            PORTC &= ~(1 << PC3);
        }
    }

    return 0;

}
```

For more description of program visit this [06-control-led-according-to-sum.c](./06-control-led-according-to-sum.c).

---

## 7. **Read 4th pin (PC3) of PORTC and send 0x10 accordingly**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRC &= ~(1 << PC3);

    uint8_t data = 0x10;

    while (1) {

        uint8_t portC_input = PINC;

        uint8_t masked_input = portC_input & (1 << PC3);

        if (masked_input) {

            PORTA = data;
        } else {

            PORTB = data;
        }
    }

    return 0;

}
```

For more description of program visit this [07-read-status-and-send.c](./07-read-status-and-send.c).

---

## 8. **Read PA0 and PA1 and send corresponding ASCII character to PORTB**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRA &= ~((1 << PA0) | (1 << PA1));
    DDRB = 0xFF;

    while (1) {

        uint8_t portA_input = PINA;

        uint8_t masked_input = portA_input & ((1 << PA0) | (1 << PA1));

        switch (masked_input) {
            case 0b00:
                PORTB = '0';
                break;
            case 0b01:
                PORTB = '1';
                break;
            case 0b10:
                PORTB = '2';
                break;
            case 0b11:
                PORTB = '3';
                break;
        }
    }

    return 0;

}
```

For more description of program visit this [08-ascii-char-output-reading-status.c](./08-ascii-char-output-reading-status.c).

---

## 9. **Check if a number from PORTA is even or odd**

```c
#include <avr/io.h>
#include <stdint.h>

int main(void) {

    DDRA = 0x00;
    DDRB |= (1 << PB0) | (1 << PB1);

    while (1) {

        uint8_t portA_input = PINA;

        uint8_t lsb = portA_input & (1 << PA0);

        if (lsb == 0) {

            PORTB |= (1 << PB0);
            PORTB &= ~(1 << PB1);
        } else {

            PORTB |= (1 << PB1);
            PORTB &= ~(1 << PB0);
        }
    }

    return 0;

}
```

For more description of program visit this [09-read-port-and-turn-on-pins.c](./09-read-port-and-turn-on-pins.c).

---

## 10. **Blink LEDs on PORTA**

```c
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    DDRA = 0xFF;

    while (1) {
        PORTA = 0b01010101;
        _delay_ms(500);
        PORTA = 0b10101010;
        _delay_ms(500);
    }

    return 0;

}
```

For more description of program visit this [10-blink-light.c](./10-blink-light.c).

---

## 11. **4-bit Binary Counter**

```c
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main(void)
{

    DDRA |= 0x0F;

    while (1)
    {

        for (uint8_t i = 0; i < 16; i++)
        {

            PORTA = i;

            _delay_ms(1000);
        }
    }

    return 0;

}
```

For more description of program visit this [11-4bit-counter.c](./11-4bit-counter.c).

---

## 12. **Square Wave Generation using Timer0 (Normal Mode)**

```c
#define F_CPU 8000000UL

#include <avr/io.h>

void Timer0Delay(void);

int main(void)
{

    DDRB |= (1 << PB3);

    while (1)
    {

        PORTB ^= (1 << PB3);

        Timer0Delay();
    }

    return 0;
}

void Timer0Delay(void)
{

    TCNT0 = 0xCE;

    TCCR0 = 0x01;

    while ((TIFR & (1 << TOV0)) == 0);

    TCCR0 = 0x00;

    TIFR = (1 << TOV0);
}
```

For more description of program visit this [12-generate-square-wave.c](./12-generate-square-wave.c).

---

## 13. **LED Blinking using Timer0 (Normal Mode)**

```c
#define F_CPU 16000000UL

#include <avr/io.h>

void Timer0Delay();

int main(void)
{

    DDRB |= (1 << PB4);

    while (1)
    {

        PORTB ^= (1 << PB4);

        Timer0Delay();
    }

    return 0;
}

void Timer0Delay()
{

    TCNT0 = 0x06;

    TCCR0 = 0x03;

    while ((TIFR & (1 << TOV0)) == 0);

    TCCR0 = 0x00;

    TIFR = (1 << TOV0);
}
```

For more description of program visit this [13-blink-led-using-timer.c](./13-blink-led-using-timer.c).

---

## 14. **1-Second Square Wave on LED using Timer0 (Normal Mode)**

```c
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>

void Timer0Delay(void);

int main(void)
{

    DDRB |= (1 << PB4);

    while (1)
    {

        PORTB ^= (1 << PB4);

        Timer0Delay();
    }

    return 0;
}

void Timer0Delay(void)
{
    uint8_t i;

    for (i = 0; i < 30; i++)
    {
        TCNT0 = 0;
        TCCR0 = 0x05;

        while ((TIFR & (1 << TOV0)) == 0);

        TCCR0 = 0x00;
        TIFR = (1 << TOV0);
    }

    TCNT0 = 0x7B;
    TCCR0 = 0x05;

    while ((TIFR & (1 << TOV0)) == 0);

    TCCR0 = 0x00;
    TIFR = (1 << TOV0);
}
```

For more description of program visit this [14-blink-led-more-delay.c](./14-blink-led-more-delay.c).

---

## 15. **Assume XTAL = 8MHz. Write a program to generate a square wave with a period of 2 ms on PB3**

```c
#define F_CPU 8000000UL

#include <avr/io.h>

void Timer0Delay()
{
    TCNT0 = 0x00;

    OCR0 = 0x7C;

    TCCR0 = 0x0B;

    while(!(TIFR & (1 << OCF0)))
    {

    }

    TIFR = 0x02;

    TCCR0 = 0x00;
}

int main(void)
{

    DDRB |= (1 << PB3);

    while(1)
    {

        PORTB ^= (1 << PB3);

        Timer0Delay();
    }

    return 0;
}
```

For more description of program visit this [15-ctc-mode-timer0.c](./15-ctc-mode-timer0.c).

---

## 16. **Assume XTAL = 8MHz. Write a program to generate a square wave with a period of 8 ms on PB3**

```c
#define F_CPU 8000000UL

#include <avr/io.h>

void Timer0Delay()
{
    TCNT0 = 0x00;

    OCR0 = 0x7C;

    TCCR0 = 0x0C;

    while(!(TIFR & (1 << OCF0)))
    {

    }

    TIFR = 0x02;

    TCCR0 = 0x00;
}

int main(void)
{

    DDRB |= (1 << PB3);

    while(1)
    {

        PORTB ^= (1 << PB3);

        Timer0Delay();
    }

    return 0;
}
```

For more description of program visit this [16-ctc-mode-more-delay.c](./16-ctc-mode-more-delay.c).

---

## 17. **Pulse Counter using Timer0 (Normal Mode) with External Clock**

```c
#define F_CPU 8000000UL
#include <avr/io.h>

int main(void)
{

    DDRC = 0xFF;

    DDRB &= ~(1 << PB0);

    TCNT0 = 0;

    TCCR0 = 0x06;

    while (1)
    {

        PORTC = TCNT0;

        if (TIFR & (1 << TOV0))
        {

            TIFR = (1 << TOV0);
        }
    }

    return 0;
}
```

For more description of program visit this [17-timer0-as-counter.c](./17-timer0-as-counter.c).

---

## 18. **Generate 8 us Square Wave on PB5 using Timer0 Overflow Interrupt**

```c
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{

    DDRB |= (1 << PB5);
    DDRC = 0x00;
    DDRD = 0xFF;

    TCCR0 = 0x01;

    TCNT0 = 0xE0;

    TIMSK |= (1 << TOIE0);

    sei();

    while (1)
    {
        PORTD = PINC;
    }

    return 0;
}

ISR(TIMER0_OVF_vect)
{

    PORTB ^= (1 << PB5);

    TCNT0 = 0xE0;
}
```

For more description of program visit this [18-overflow-interrupt.c](./18-overflow-interrupt.c).

---

## 19. **Generate 4 us Square Wave on PD5 using Timer2 Compare Match Interrupt**

```c
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

int main(void)
{

    DDRD |= (1 << PD5);
    DDRB = 0xFF;

    TCNT2 = 0x00;

    OCR2 = 0x0F;

    TCCR2 = (1 << WGM21) | (1 << CS20);

    TIMSK |= (1 << OCIE2);

    sei();

    while (1)
    {
        for (uint8_t i = 0; ; i++)
        {
            PORTB = i;
        }
    }

    return 0;
}

ISR(TIMER2_COMP_vect)
{

    PORTD ^= (1 << PD5);
}
```

For more description of program visit this [19-compare-match-interrupt.c](./19-compare-match-interrupt.c).

---

## 20. **Play Melody Notes (C-D-E-D) on Buzzer using Timer0 Compare Interrupt**

```c
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{

    DDRD |= (1 << PD3);

    TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);

    TIMSK |= (1 << OCIE0);

    OCR0 = 244;

    sei();

    while (1)
    {

        OCR0 = 244;
        _delay_ms(500);

        OCR0 = 217;
        _delay_ms(500);

        OCR0 = 194;
        _delay_ms(500);

        OCR0 = 217;
        _delay_ms(500);
    }

    return 0;
}

ISR(TIMER0_COMP_vect)
{
    PORTD ^= (1 << PD3);
}
```

For more description of program visit this [20-play-melody.c](./20-play-melody.c).

