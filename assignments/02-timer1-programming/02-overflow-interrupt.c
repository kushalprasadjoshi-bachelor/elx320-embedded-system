/*
* Program: External Pulse Counter using Timer1 with Overflow Interrupt
* MCU    : ATmega32
*
* Objective:
*   Count external pulses applied to the T1 pin (PD5) using Timer1 configured
*   in counter mode. Whenever the counter overflows, an interrupt is triggered
*   and an LED connected to PB0 is toggled.
*
* -------------------------------------------------------------------
* GIVEN DATA
* -------------------------------------------------------------------
*
* Microcontroller      : ATmega32
*
* External Pulse Input : T1 pin (PD5)
*
* Timer Used           : Timer1 (16-bit counter)
*
* Interrupt Used       : Timer1 Overflow Interrupt
*
* LED Output           : PB0
*
* -------------------------------------------------------------------
* TIMER1 COUNTER OPERATION
* -------------------------------------------------------------------
*
* Timer1 is a 16-bit timer/counter.
*
* Counter range:
*
*      0 -> 65535
*
* When the next pulse arrives after 65535:
*
*      65535 -> 0
*
* This event is called **Overflow**.
*
* When overflow occurs:
*
*      TOV1 flag is set
*
* If overflow interrupt is enabled, the microcontroller
* automatically jumps to the Interrupt Service Routine (ISR).
*
* -------------------------------------------------------------------
* EXTERNAL CLOCK CONFIGURATION
* -------------------------------------------------------------------
*
* External pulses are applied to the T1 pin (PD5).
*
* Each falling edge of the pulse signal increments the counter.
*
* Example:
*
* Pulse 1 -> TCNT1 = 1
* Pulse 2 -> TCNT1 = 2
* Pulse 3 -> TCNT1 = 3
*
* When TCNT1 reaches 65535 and another pulse arrives,
* overflow occurs and the interrupt is triggered.
*
* -------------------------------------------------------------------
* TIMER1 REGISTER CONFIGURATION
* -------------------------------------------------------------------
*
* TCCR1A = 0x00
*
* Binary : 0000 0000
*
* Meaning:
*   Normal mode operation (no PWM)
*
* -------------------------------------------------------------
*
* TCCR1B = (1 << CS12) | (1 << CS11)
*
* Binary (CS12 CS11 CS10) = 110
*
* Meaning:
*
* External clock source on T1 pin
* Trigger on FALLING EDGE
*
* -------------------------------------------------------------
*
* TIMSK = (1 << TOIE1)
*
* TOIE1 = Timer1 Overflow Interrupt Enable
*
* -------------------------------------------------------------
*
* sei()
*
* Enables global interrupts.
*/

#include <avr/io.h>
#include <avr/interrupt.h>

/*
* ---------------------------------------------------------
* Interrupt Service Routine
* ---------------------------------------------------------
*
* This function runs automatically when Timer1 overflow occurs.
*/

ISR(TIMER1_OVF_vect)
{
    /*
    * Toggle LED connected to PB0
    */

    PORTB ^= (1 << PB0);
}

int main(void)
{
    /*
    * ---------------------------------------------------------
    * Step 1: Configure LED pin as OUTPUT
    * ---------------------------------------------------------
    */

    DDRB |= (1 << PB0);

    /*
    * ---------------------------------------------------------
    * Step 2: Configure T1 pin (PD5) as INPUT
    * ---------------------------------------------------------
    */

    DDRD &= ~(1 << PD5);

    /*
    * ---------------------------------------------------------
    * Step 3: Initialize Timer1 Counter
    * ---------------------------------------------------------
    */

    TCNT1 = 0;

    /*
    * ---------------------------------------------------------
    * Step 4: Configure Timer1 in Normal Mode
    * ---------------------------------------------------------
    */

    TCCR1A = 0x00;

    /*
    * ---------------------------------------------------------
    * Step 5: Configure External Clock Source
    * ---------------------------------------------------------
    *
    * Falling edge trigger on T1 pin
    */

    TCCR1B = (1 << CS12) | (1 << CS11);

    /*
    * ---------------------------------------------------------
    * Step 6: Enable Timer1 Overflow Interrupt
    * ---------------------------------------------------------
    */

    TIMSK |= (1 << TOIE1);

    /*
    * ---------------------------------------------------------
    * Step 7: Enable Global Interrupts
    * ---------------------------------------------------------
    */

    sei();

    /*
    * ---------------------------------------------------------
    * Step 8: Infinite Loop
    * ---------------------------------------------------------
    *
    * Counting happens automatically in hardware.
    * Interrupt will trigger when overflow occurs.
    */

    while (1)
    {
        // No code required here
    }

    return 0;
}

/*
* ======================= KEY NOTES =======================
*
* 1. Timer1
*    - 16-bit timer/counter
*    - Count range: 0 -> 65535
*
* 2. T1 Pin
*    - PD5 is the external clock input for Timer1.
*
* 3. Counter Mode
*    - External pulses increment the counter.
*
* 4. Falling Edge Trigger
*    - Counter increments when signal goes HIGH -> LOW.
*
* 5. Overflow Condition
*    - Occurs when counter changes from 65535 -> 0.
*
* 6. Overflow Interrupt
*    - Enabled using:
*          TIMSK |= (1 << TOIE1);
*
* 7. Interrupt Service Routine
*    - ISR(TIMER1_OVF_vect) executes automatically on overflow.
*
* 8. Global Interrupt Enable
*    - Required to allow interrupts:
*          sei();
*
* 9. LED Toggle
*    - Each overflow toggles PB0.
*
* 10. Advantage of Interrupt Method
*     - CPU does not need to continuously check the counter.
*     - Hardware automatically triggers ISR.
*/