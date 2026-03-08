/*
Program:
Assume XTAL = 8MHz. Write a program to generate a square wave with a period of 2 ms on PB3
using Timer0 in CTC (Clear Timer on Compare Match) mode.

Explanation:
- Square wave period = 2 ms
- One toggle every 1 ms (HIGH -> LOW or LOW -> HIGH)
- Timer0 will generate 1 ms delay
- PB3 is toggled after each delay
*/

#define F_CPU 8000000UL     // Define CPU frequency as 8 MHz

#include <avr/io.h>         // AVR register definitions

/*
------------------------------------------------------------
Timer0Delay()
------------------------------------------------------------
Purpose:
Generates a delay of approximately 1 ms using Timer0 in CTC mode.

Registers Used:
TCNT0  -> Timer0 counter register
OCR0   -> Output Compare Register
TCCR0  -> Timer0 Control Register
TIFR   -> Timer Interrupt Flag Register
OCF0   -> Output Compare Flag for Timer0

Timer Calculation:
Clock Frequency = 8 MHz

Prescale | Timer Clock Frequency | Timer Tick Time | Counts for 1 ms
------------------------------------------------------------
None     | 8,000,000 Hz         | 0.125 µs        | 8000 counts
8        | 1,000,000 Hz         | 1 µs            | 1000 counts
64       | 125,000 Hz           | 8 µs            | 125 counts     <-- Chosen Prescaler
256      | 31,250 Hz            | 32 µs           | 31.25 counts
1024     | 7,812.5 Hz           | 128 µs          | 7.8125 counts

Using Prescaler = 64

Timer Frequency = 8,000,000 / 64
                = 125000 Hz

Timer tick time = 1 / 125000
                = 8 µs

Required Delay = 1 ms = 1000 µs

Number of counts required:
1000 / 8 = 125 counts

Since counting starts from 0:
OCR0 = 124 (0x7C)
------------------------------------------------------------
*/

void Timer0Delay()
{
    TCNT0 = 0x00;           // Clear Timer0 counter

    OCR0 = 0x7C;            // Set compare value for 1 ms delay (124)

    /*
    TCCR0 = 0x0B

    Binary: 0000 1011

    Bit Explanation:
    WGM01 = 1  -> Enable CTC Mode
    WGM00 = 0

    CS02 = 0
    CS01 = 1
    CS00 = 1

    Prescaler = 64
    */

    TCCR0 = 0x0B;           // Start Timer0 in CTC mode with prescaler 64

    /*
    Wait until compare match occurs.

    OCF0 bit in TIFR becomes 1 when TCNT0 == OCR0
    */

    while(!(TIFR & (1 << OCF0)))
    {
        // Wait here until compare match happens
    }

    /*
    Clear compare match flag by writing 1 to OCF0
    TIFR = (1 << OCF0) clears the OCF0 flag
    */

    TIFR = 0x02;           // Clear OCF0 flag

    TCCR0 = 0x00;           // Stop Timer0
}

/*
------------------------------------------------------------
Main Program
------------------------------------------------------------
*/

int main(void)
{
    /*
    DDRB = Data Direction Register for Port B

    Setting PB3 as OUTPUT
    */

    DDRB |= (1 << PB3);

    while(1)
    {
        /*
        Toggle PB3

        XOR operation flips the bit:
        0 -> 1
        1 -> 0
        */

        PORTB ^= (1 << PB3);

        /*
        Call delay function (1 ms delay)
        */

        Timer0Delay();
    }

    return 0;
}

/*
====================== KEY NOTES ==================
1. Crystal Frequency (XTAL) = 8 MHz

2. Timer Used:
   Timer0 operating in CTC (Clear Timer on Compare Match) mode.

3. Prescaler Used = 64

4. Timer Frequency Calculation:
   Timer Frequency = 8,000,000 / 64
                   = 125000 Hz

5. Timer Tick Time:
   1 / 125000 = 8 µs

6. Required Delay:
   1 ms = 1000 µs

7. Timer Counts Required:
   1000 / 8 = 125 counts

8. OCR0 Value:
   Since counting starts from 0,
   OCR0 = 124 (0x7C)

9. Wave Generation Logic:
   PB3 toggles every 1 ms.
   HIGH time = 1 ms
   LOW time  = 1 ms
   Total period = 2 ms square wave.

10. Registers Used:
    TCCR0  → Timer0 control register
    TCNT0  → Timer counter register
    OCR0   → Compare register
    TIFR   → Timer interrupt flag register

11. Flag Used:
    OCF0 (Output Compare Flag)

12. Flag Clearing Rule:
    Write logic 1 to OCF0 to clear the flag.

13. Pin Operation:
    PORTB ^= (1 << PB3)
    This toggles PB3 output.
*/