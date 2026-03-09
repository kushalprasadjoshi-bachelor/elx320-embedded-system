/*
 * Program: Pulse Counter using Timer0 (Normal Mode) with External Clock
 * MCU    : ATmega32
 *
 * Objective:
 *   Count external pulses applied to the T0 pin (PB0) using Timer0 configured
 *   as a counter. The counter increments on every falling edge of the pulse
 *   signal. The current count value is continuously displayed on PORTC.
 *                  __________________________________
                    |                                |====> PORTC
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
                    |                                |
           _   _   _|PB0                             |
         _| |_| |_| |________________________________|
 *
 * -------------------------------------------------------------------
 * GIVEN DATA
 * -------------------------------------------------------------------
 *
 * Microcontroller      : ATmega32
 * Clock Frequency      : 8 MHz
 *
 * External Pulse Input : T0 pin (PB0)
 *
 * Counting Mode        : Counter mode (external clock source)
 *
 * Trigger Edge         : Falling edge of external pulse
 *
 * Display Port         : PORTC
 *
 * -------------------------------------------------------------------
 * TIMER0 COUNTER OPERATION
 * -------------------------------------------------------------------
 *
 * Timer0 can work in two ways:
 *
 * 1. Timer Mode   -> Uses internal CPU clock
 * 2. Counter Mode -> Uses external clock from pin T0 (PB0)
 *
 * In this program we use **Counter Mode**.
 *
 * External pulses applied on PB0 will increment the Timer0 counter.
 *
 * Counting condition:
 *
 *      Every falling edge on PB0 -> TCNT0 increments by 1
 *
 * Example:
 *
 * Pulse edges detected:
 *
 *     Pulse 1 -> TCNT0 = 1
 *     Pulse 2 -> TCNT0 = 2
 *     Pulse 3 -> TCNT0 = 3
 *     ...
 *
 * The value stored in TCNT0 is sent directly to PORTC.
 *
 * -------------------------------------------------------------------
 * TIMER0 REGISTER CONFIGURATION
 * -------------------------------------------------------------------
 *
 * TCCR0 = 0x06
 *
 * Binary : 0000 0110
 *
 * Bit Explanation:
 *
 * FOC0  = 0
 * WGM00 = 0
 * COM01 = 0
 * COM00 = 0
 * WGM01 = 0  -> Normal Mode
 *
 * CS02 = 1
 * CS01 = 1
 * CS00 = 0
 *
 * CS02 CS01 CS00 = 110
 *
 * This selects:
 *
 * External clock source on T0 pin
 * Clock on FALLING EDGE
 *
 * Therefore:
 *
 * Each falling edge on PB0 increments Timer0.
*/

#define F_CPU 8000000UL
#include <avr/io.h>

int main(void)
{
    /*
     * ---------------------------------------------------------
     * Step 1: Configure PORTC as OUTPUT
     * ---------------------------------------------------------
     *
     * PORTC will display the counter value.
    */

    DDRC = 0xFF;

    /*
     * ---------------------------------------------------------
     * Step 2: Configure PB0 (T0 pin) as INPUT
     * ---------------------------------------------------------
     *
     * External pulses will be applied here.
    */

    DDRB &= ~(1 << PB0);

    /*
     * ---------------------------------------------------------
     * Step 3: Initialize Timer0 Counter
     * ---------------------------------------------------------
    */

    TCNT0 = 0;

    /*
     * ---------------------------------------------------------
     * Step 4: Configure Timer0 as Counter
     * ---------------------------------------------------------
     *
     * External clock on T0 pin
     * Falling edge trigger
    */

    TCCR0 = 0x06;

    /*
     * ---------------------------------------------------------
     * Step 5: Infinite Loop
     * ---------------------------------------------------------
    */

    while (1)
    {
        /*
         * Display counter value on PORTC
         *
         * Each external pulse increases TCNT0
         * so PORTC shows the pulse count.
        */

        PORTC = TCNT0;

        /*
         * When counter overflows (255 -> 0),
         * TOV0 flag becomes 1.
        */

        if (TIFR & (1 << TOV0))
        {
            /*
             * Clear overflow flag
            */

            TIFR = (1 << TOV0);
        }
    }

    /* 
    ==========Another logic ==========
    while (1) {
        do {
            PORTC = TCNT0;
        } while (TIFR & (1 << TOV0) == 0);
        
        TCNT0 = 0x00; <-- No need to manually reset the counter after ovverflow
                            The counters are automatically reset to 0 after overflow
        TIFR = (1 << TOV0)
    }
    */

    return 0;
}

/*
 * ======================= KEY NOTES =======================
 *
 * 1. Timer0 Counter Mode
 *    - Timer0 counts external pulses instead of internal clock.
 *
 * 2. T0 Pin
 *    - PB0 is the dedicated external clock input for Timer0.
 *
 * 3. External Clock Source
 *    - Falling edge of pulse increments TCNT0.
 *
 * 4. Timer0 Capacity
 *    - 8-bit counter
 *    - Maximum value = 255
 *
 * 5. Overflow Condition
 *    - When TCNT0 goes from 255 -> 0
 *    - TOV0 flag becomes 1.
 *
 * 6. Displaying Count
 *    - TCNT0 value is directly written to PORTC
 *    - LEDs connected to PORTC will show the binary count.
 *
 * 7. TCCR0 = 0x06
 *    - Normal Mode
 *    - External clock on T0 pin
 *    - Trigger on falling edge.
 *
 * 8. Counter Reset
 *    - Program initializes TCNT0 = 0 at start.
 *
 * 9. Application
 *    - Pulse counting
 *    - Frequency measurement
 *    - Event counting
*/