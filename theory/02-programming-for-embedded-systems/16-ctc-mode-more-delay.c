/*
Program:
Assume XTAL = 8MHz. Write a program to generate a square wave with a period of 8 ms on PB3
using Timer0 in CTC mode.

Explanation:
- Timer delay used = 8/2 ms = 4 ms
- PB3 is toggled after every delay
- Timer0 is configured in CTC mode
*/

#define F_CPU 8000000UL      // Define CPU clock frequency (8 MHz)

#include <avr/io.h>          // Include AVR register definitions

/*
------------------------------------------------------------
Timer0Delay()
------------------------------------------------------------
Purpose:
Generates approximately 4 ms delay using Timer0 in CTC mode.

Registers Used:
TCNT0  -> Timer0 Counter Register
OCR0   -> Output Compare Register
TCCR0  -> Timer Control Register
TIFR   -> Timer Interrupt Flag Register
OCF0   -> Output Compare Flag

Timer Calculation:

Clock Frequency = 8 MHz

Prescale | Timer Clock Frequency | Timer Tick Time | Counts for 1 ms
------------------------------------------------------------
None     | 8,000,000 Hz         | 0.125 µs        | 8000 counts
8        | 1,000,000 Hz         | 1 µs            | 1000 counts
64       | 125,000 Hz           | 8 µs            | 125 counts    
256      | 31,250 Hz            | 32 µs           | 31.25 counts    <-- Chosen Prescaler
1024     | 7,812.5 Hz           | 128 µs          | 7.8125 counts

Using Prescaler = 256

Timer Frequency = 8000000 / 256
                = 31250 Hz

Timer tick time = 1 / 31250
                = 32 µs

Required Delay = 4 ms = 4000 µs

Number of counts required:
4000 / 32 = 125 counts

Since timer starts from 0:
OCR0 = 124 (0x7C)
------------------------------------------------------------
*/

void Timer0Delay()
{
    TCNT0 = 0x00;        // Clear timer counter

    OCR0 = 0x7C;         // Set compare value for 4 ms delay (124)

    /*
    TCCR0 = 0x0C

    Binary: 0000 1100

    Bit Explanation:
    WGM01 = 1  -> CTC mode enabled
    WGM00 = 0

    CS02 = 1
    CS01 = 0
    CS00 = 0

    Prescaler = 256
    */

    TCCR0 = 0x0C;        // Start Timer0 in CTC mode with prescaler 256

    /*
    Wait until compare match occurs
    OCF0 becomes 1 when TCNT0 == OCR0
    */

    while(!(TIFR & (1 << OCF0)))
    {
        // Wait for compare match
    }

    /*
    Clear compare match flag by writing 1 to OCF0
    TIFR = (1 << OCF0);
    */

    TIFR = 0x02;        // Clear OCF0 flag

    TCCR0 = 0x00;        // Stop Timer0
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

    Set PB3 as OUTPUT
    */

    DDRB |= (1 << PB3);

    while(1)
    {
        /*
        Toggle PB3 using XOR operation
        */

        PORTB ^= (1 << PB3);

        /*
        Generate 4 ms delay
        */

        Timer0Delay();
    }

    return 0;
}

/*
====================== KEY NOTES ==================
1. Crystal Frequency (XTAL) = 8 MHz

2. Timer Used:
   Timer0 operating in CTC mode.

3. Prescaler Used = 256

4. Timer Frequency Calculation:
   Timer Frequency = 8,000,000 / 256
                   = 31250 Hz

5. Timer Tick Time:
   1 / 31250 = 32 µs

6. Required Delay:
   4 ms = 4000 µs

7. Timer Counts Required:
   4000 / 32 = 125 counts

8. OCR0 Value:
   OCR0 = 124 (0x7C)

9. Timer Control Register:
   TCCR0 = 0x0C

   Bit Explanation:
   WGM01 = 1 → Enable CTC Mode
   CS02  = 1 → Prescaler 256

10. Wave Generation Logic:
    PB3 toggles every 4 ms.

    HIGH time = 4 ms
    LOW time  = 4 ms

    Total period = 8 ms square wave.

11. Important Hardware Behavior:
    Timer counts from 0 to OCR0.
    When TCNT0 equals OCR0, OCF0 flag becomes 1.

12. Timer Stop:
    TCCR0 = 0x00 stops Timer0.

13. Pin Configuration:
    DDRB |= (1 << PB3) sets PB3 as output.
*/