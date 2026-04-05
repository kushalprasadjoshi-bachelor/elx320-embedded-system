/*
 * Program: Generate 4 us Square Wave on PD5 using Timer2 Compare Match Interrupt
 *          while continuously displaying 00 to FF on PORTB
 * MCU    : ATmega32
 *
 * Objective:
 *   1. Generate a square wave of period 4 us on PD5
 *      using Timer2 Compare Match Interrupt
 *   2. Simultaneously display 00 to FF continuously on PORTB
 *
 * -------------------------------------------------------------------
 * GIVEN DATA
 * -------------------------------------------------------------------
 *
 * Clock Frequency (F_CPU) = 8 MHz
 *
 * Required square wave period = 4 us
 *
 * Therefore:
 *
 *      Toggle delay = T / 2
 *                   = 4 us / 2
 *                   = 2 us
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
 *             = 2 us / 0.125 us
 *             = 16 counts
 *
 * Timer2 is 8-bit.
 *
 * In CTC / Compare Match mode:
 *
 *      Timer counts from 0 to OCR2
 *
 * Since counting starts from 0:
 *
 *      OCR2 = 16 - 1
 *           = 15
 *           = 0x0F
 *
 * -------------------------------------------------------------------
 * TIMER2 CONFIGURATION
 * -------------------------------------------------------------------
 *
 * Timer2 in CTC Mode
 *
 * No prescaler used
 *
 * TCCR2 = 0x09
 *
 * Binary:
 *
 *      0000 1001
 *
 *      WGM21 = 1  -> CTC mode
 *      CS22 CS21 CS20 = 001 -> No prescaler
 *
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

int main(void)
{
    /*
     * ---------------------------------------------------------
     * Step 1: Configure Ports
     * ---------------------------------------------------------
    */

    DDRD |= (1 << PD5);     // PD5 as output for square wave
    DDRB = 0xFF;            // PORTB as output for display

    /*
     * ---------------------------------------------------------
     * Step 2: Configure Timer2
     * ---------------------------------------------------------
    */

    TCNT2 = 0x00;           // Start counting from 0

    /*
     * OCR2 = 15
     * Interrupt after 16 counts = 2 us
    */

    OCR2 = 0x0F;

    /*
     * Timer2 CTC mode, no prescaler
    */

    TCCR2 = (1 << WGM21) | (1 << CS20);

    /*
     * ---------------------------------------------------------
     * Step 3: Enable Compare Match Interrupt
     * ---------------------------------------------------------
    */

    TIMSK |= (1 << OCIE2);

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
     * Display 00 to FF continuously
    */

    while (1)
    {
        for (uint8_t i = 0; ; i++)
        {
            PORTB = i;
        }
    }

    return 0;
}

/*
 * ---------------------------------------------------------
 * Interrupt Service Routine
 * ---------------------------------------------------------
 *
 * Executes every 2 us
*/

ISR(TIMER2_COMP_vect)
{
    /*
     * Toggle PD5
    */

    PORTD ^= (1 << PD5);
}

/*
 * ======================= KEY NOTES =======================
 *
 * 1. Timer2
 *    - 8-bit timer
 *    - Used in Compare Match Interrupt mode
 *
 * 2. Delay Calculation
 *    - Required half period = 2 us
 *    - Timer tick = 0.125 us
 *    - Counts = 16
 *
 * 3. OCR2 Value
 *    - Since counting starts from 0
 *    - OCR2 = 15 = 0x0F
 *
 * 4. Compare Match Interrupt
 *    - Interrupt occurs when:
 *          TCNT2 == OCR2
 *
 * 5. Interrupt Enable
 *    - Enabled using:
 *          TIMSK |= (1 << OCIE2);
 *
 * 6. Timer Mode
 *    - CTC mode
 *    - Counter auto resets after compare match
 *
 * 7. Simultaneous Operation
 *    - Interrupt generates waveform
 *    - Main loop displays 00 to FF on PORTB
 *
 * 8. Important Correction
 *    - TCNT2 should start from 0
 *    - OCR2 = 0x0F (not 0x10)
 *
*/