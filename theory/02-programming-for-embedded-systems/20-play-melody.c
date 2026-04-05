/*
 * Program: Play Melody Notes (C-D-E-D) on Buzzer using Timer0 Compare Interrupt
 * MCU    : ATmega32
 * Clock  : 16 MHz
 *
 * Objective:
 *   Play the melody sequence:
 *
 *      C → D → E → D
 *
 *   repeatedly on a buzzer connected to PD3
 *   using Timer0 Compare Match Interrupt mode.
 *
 * -------------------------------------------------------------------
 * NOTE FREQUENCIES AND OCR VALUES
 * -------------------------------------------------------------------
 *
 * NOTE    Frequency      OCR0 Value
 * ----------------------------------
 * C       ~523 Hz        244
 * D       ~587 Hz        217
 * E       ~659 Hz        194
 *
 * -------------------------------------------------------------------
 * TIMER CONFIGURATION
 * -------------------------------------------------------------------
 *
 * Timer0 used in CTC Mode
 *
 * Prescaler = 64
 *
 * TCCR0 = 0x0B
 *
 * Binary:
 *
 *      0000 1011
 *
 *      WGM01 = 1  -> CTC mode
 *      CS01  = 1
 *      CS00  = 1  -> Prescaler 64
 *
 * Compare Match Interrupt enabled
 *
 *      TIMSK |= (1 << OCIE0);
 *
 * -------------------------------------------------------------------
 * WORKING PRINCIPLE
 * -------------------------------------------------------------------
 *
 * Every compare match interrupt toggles PD3.
 *
 * Changing OCR0 changes interrupt frequency,
 * which changes the output tone frequency.
 *
 * Smaller OCR0 → Faster toggling → Higher pitch
 * Larger OCR0  → Slower toggling → Lower pitch
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
 * ---------------------------------------------------------
 * Main Program
 * ---------------------------------------------------------
*/

int main(void)
{
    /*
     * Step 1: Configure PD3 as output for buzzer
    */

    DDRD |= (1 << PD3);

    /*
     * Step 2: Configure Timer0
     *
     * CTC mode
     * Prescaler = 64
    */

    TCCR0 = (1 << WGM01) | (1 << CS01) | (1 << CS00);

    /*
     * Step 3: Enable Compare Match Interrupt
    */

    TIMSK |= (1 << OCIE0);

    /*
     * Step 4: Set initial note = C
    */

    OCR0 = 244;

    /*
     * Step 5: Enable global interrupts
    */

    sei();

    /*
     * Step 6: Play melody repeatedly
    */

    while (1)
    {
        /*
         * C note
        */

        OCR0 = 244;
        _delay_ms(500);

        /*
         * D note
        */

        OCR0 = 217;
        _delay_ms(500);

        /*
         * E note
        */

        OCR0 = 194;
        _delay_ms(500);

        /*
         * D note again
        */

        OCR0 = 217;
        _delay_ms(500);
    }

    return 0;
}

/*
 * ---------------------------------------------------------
 * Interrupt Service Routine
 * ---------------------------------------------------------
 *
 * Executes automatically at compare match
 * and toggles buzzer pin.
*/

ISR(TIMER0_COMP_vect)
{
    PORTD ^= (1 << PD3);
}

/*
 * ======================= KEY NOTES =======================
 *
 * 1. Timer0 Mode
 *    - Compare Match Interrupt Mode (CTC)
 *
 * 2. Prescaler
 *    - 64
 *
 * 3. Melody Notes
 *    - C = 244
 *    - D = 217
 *    - E = 194
 *
 * 4. Working Principle
 *    - Interrupt toggles PD3
 *    - OCR0 controls tone frequency
 *
 * 5. Important Concept
 *    - Lower OCR0 -> Higher frequency
 *    - Higher OCR0 -> Lower frequency
 *
 * 6. Melody Sequence
 *    - C -> D -> E -> D
 *    - Repeats continuously
 *
 * 7. Buzzer Output
 *    - Square wave generated on PD3
 *
*/