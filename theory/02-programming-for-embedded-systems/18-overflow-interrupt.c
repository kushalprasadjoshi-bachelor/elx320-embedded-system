/*
 * Program: Generate 8 us Square Wave on PB5 using Timer0 Overflow Interrupt
 *          while simultaneously transferring data from PORTC to PORTD
 * MCU    : ATmega32
 *
 * Objective:
 *   1. Generate a square wave of period 8 us on PB5
 *      using Timer0 Overflow Interrupt
 *   2. Simultaneously transfer data from PORTC to PORTD
 *
 * -------------------------------------------------------------------
 * GIVEN DATA
 * -------------------------------------------------------------------
 *
 * Clock Frequency (F_CPU) = 8 MHz
 *
 * Required square wave period = 8 us
 *
 * Therefore:
 *
 *      Toggle delay = T / 2
 *                   = 8 us / 2
 *                   = 4 us
 *
 * -------------------------------------------------------------------
 * TIMER CLOCK CALCULATION
 * -------------------------------------------------------------------
 *
 * Clock time:
 *
 *      Tclk = 1 / F_CPU
 *           = 1 / 8 MHz
 *           = 0.125 us
 *
 * Required counts:
 *
 *      Counts = Delay / Clock time
 *             = 4 us / 0.125 us
 *             = 32 counts
 *
 * Timer0 is 8-bit:
 *
 *      Maximum count = 256
 *
 * Therefore initial value:
 *
 *      TCNT0 = 256 - 32
 *            = 224
 *            = 0xE0
 *
 * -------------------------------------------------------------------
 * TIMER CONFIGURATION
 * -------------------------------------------------------------------
 *
 * Timer0 used in Normal Mode
 *
 * No prescaler used
 *
 * TCCR0 = 0x01
 *
 * CS02 CS01 CS00 = 001
 *
 * Clock source = F_CPU
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    /*
     * ---------------------------------------------------------
     * Step 1: Configure Ports
     * ---------------------------------------------------------
    */

    DDRB |= (1 << PB5);     // PB5 as output for square wave
    DDRC = 0x00;            // PORTC as input
    DDRD = 0xFF;            // PORTD as output

    /*
     * ---------------------------------------------------------
     * Step 2: Configure Timer0
     * ---------------------------------------------------------
     *
     * Normal mode
     * No prescaler
    */

    TCCR0 = 0x01;

    /*
     * Load initial count value
    */

    TCNT0 = 0xE0;

    /*
     * ---------------------------------------------------------
     * Step 3: Enable Timer0 Overflow Interrupt
     * ---------------------------------------------------------
    */

    TIMSK |= (1 << TOIE0);

    /*
     * ---------------------------------------------------------
     * Step 4: Enable Global Interrupt
     * ---------------------------------------------------------
    */

    sei();

    /*
     * ---------------------------------------------------------
     * Step 5: Main Loop
     * ---------------------------------------------------------
     *
     * Simultaneous data transfer
    */

    while (1)
    {
        PORTD = PINC;
    }

    return 0;
}

/*
 * ---------------------------------------------------------
 * Interrupt Service Routine
 * ---------------------------------------------------------
 *
 * Executes automatically every 4 us
*/

ISR(TIMER0_OVF_vect)
{
    /*
     * Toggle PB5
    */

    PORTB ^= (1 << PB5);

    /*
     * Reload timer for next 4 us delay
    */

    TCNT0 = 0xE0;
}

/*
 * ======================= KEY NOTES =======================
 *
 * 1. Timer0
 *    - 8-bit timer
 *    - Maximum count = 256
 *
 * 2. Delay Calculation
 *    - Required half period = 4 us
 *    - Timer tick = 0.125 us
 *    - Counts = 32
 *
 * 3. Initial Value
 *    - TCNT0 = 256 - 32 = 224 = 0xE0
 *
 * 4. Overflow Interrupt
 *    - Interrupt occurs when timer overflows
 *    - Enabled using:
 *          TIMSK |= (1 << TOIE0);
 *
 * 5. ISR
 *    - Automatically toggles PB5
 *    - Reloads TCNT0
 *
 * 6. Simultaneous Operation
 *    - Main loop transfers PORTC → PORTD
 *    - Interrupt independently generates waveform
 *
 * 7. Important Advantage
 *    - CPU can perform other tasks while waveform is generated
 *
*/