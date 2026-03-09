/*
* Program: Pulse Counter using Timer1 (Normal Mode) on T1 Pin
* MCU    : ATmega32
*
* Objective:
*   Count external pulses applied to the T1 pin (PD5) using Timer1 configured
*   as a counter. The counter increments on every falling edge of the pulse
*   signal. The lower 8 bits of the counter value are continuously displayed
*   on PORTA using polling method.
*
* -------------------------------------------------------------------
* GIVEN DATA
* -------------------------------------------------------------------
*
* Microcontroller      : ATmega32
* External Pulse Input : T1 pin (PD5)
*
* Counting Method      : Polling
*
* Timer Used           : Timer1 (16-bit timer)
*
* Display Port         : PORTA
*
* -------------------------------------------------------------------
* TIMER1 COUNTER OPERATION
* -------------------------------------------------------------------
*
* Timer1 can operate in two modes:
*
* 1. Timer Mode
*    - Uses internal CPU clock.
*
* 2. Counter Mode
*    - Uses external clock applied to T1 pin (PD5).
*
* In this program we use **Counter Mode**.
*
* Each falling edge of the pulse signal applied on T1 pin
* increments the Timer1 counter by 1.
*
* Example:
*
* Pulse edges detected:
*
*   Pulse 1 -> TCNT1 = 1
*   Pulse 2 -> TCNT1 = 2
*   Pulse 3 -> TCNT1 = 3
*   ...
*
* Since Timer1 is a 16-bit counter:
*
* Minimum value = 0
* Maximum value = 65535
*
* However, PORTA is an 8-bit port, so only the lower 8 bits
* of TCNT1 are displayed.
*
* -------------------------------------------------------------------
* TIMER1 REGISTER CONFIGURATION
* -------------------------------------------------------------------
*
* TCCR1A = 0x00
*
* Binary: 0000 0000
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
* This selects:
*
* External clock source on T1 pin
* Trigger on FALLING EDGE
*
* Therefore:
*
* Each falling edge of the pulse signal on PD5 increments TCNT1.
*/

#include <avr/io.h>

int main(void)
{
    /*
    * ---------------------------------------------------------
    * Step 1: Configure PORTA as OUTPUT
    * ---------------------------------------------------------
    *
    * PORTA will display the counter value.
    */

    DDRA = 0xFF;

    /*
    * ---------------------------------------------------------
    * Step 2: Configure T1 Pin (PD5) as INPUT
    * ---------------------------------------------------------
    *
    * External pulses will be applied here.
    */

    DDRD &= ~(1 << PD5);

    /*
    * ---------------------------------------------------------
    * Step 3: Initialize Timer1 Counter
    * ---------------------------------------------------------
    */

    TCNT1 = 0; // Reset counter (TCNT1 = TCNT1A + TCNT1B)

    /*
    * ---------------------------------------------------------
    * Step 4: Configure Timer1 in Normal Mode
    * ---------------------------------------------------------
    */

    TCCR1A = 0x00;

    /*
    * ---------------------------------------------------------
    * Step 5: Configure External Clock on Falling Edge
    * ---------------------------------------------------------
    *
    * CS12 = 1
    * CS11 = 1
    * CS10 = 0
    */

    TCCR1B = (1 << CS12) | (1 << CS11);

    /*
    * ---------------------------------------------------------
    * Step 6: Infinite Loop
    * ---------------------------------------------------------
    */

    while (1)
    {
        /*
        * Display the lower 8 bits of the counter
        * on PORTA continuously.
        */

        PORTA = TCNT1;
    }

    return 0; // Not compulsory because it's unreachable
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
*    - External pulses are used instead of CPU clock.
*
* 4. Falling Edge Trigger
*    - Counter increments when signal goes HIGH -> LOW.
*
* 5. Polling Method
*    - Program continuously reads TCNT1
*    - No interrupt is used.
*
* 6. Display Limitation
*    - PORTA is 8-bit
*    - Only lower 8 bits of TCNT1 are visible.
*
* 7. Overflow
*    - Timer1 overflows when count reaches 65535 -> 0.
*    - Overflow handling is not required for this program.
*
* 8. Application
*    - Pulse counting
*    - Event monitoring
*    - Frequency measurement
*/