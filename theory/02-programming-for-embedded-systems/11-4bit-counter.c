/*
 * Program: 4-bit Binary Counter
 * MCU    : ATmega32
 * Objective:
 *   - Create a 4-bit up counter using PORTA
 *   - Output changes every 1 second
 *   - Counter counts from 0 to 15 repeatedly
 */

#define F_CPU 1000000UL      // Define CPU clock frequency (1 MHz)
                            // MUST be defined before including delay library

#include <avr/io.h>          // AVR I/O register definitions
#include <util/delay.h>     // For _delay_ms()
#include <stdint.h>         // For standard integer types

int main(void)
{
    // -------------------------------------------------------------
    // Step 1: Configure PORTA
    // -------------------------------------------------------------
    /*
     * Set only lower 4 bits of PORTA (PA0–PA3) as OUTPUT
     * 0x0F = 0000 1111
     * PA0–PA3 → Output (LEDs / output pins)
     * PA4–PA7 → Unchanged (remain input if previously input)
     */
    DDRA |= 0x0F;

    // -------------------------------------------------------------
    // Step 2: Infinite loop
    // -------------------------------------------------------------
    while (1)
    {
        /*
         * 4-bit counter loop
         * Counts from 0 to 15 (2^4 = 16 states)
         */
        for (uint8_t i = 0; i < 16; i++)
        {
            /*
             * Output counter value to PORTA
             * Only lower 4 bits are physically used
             */
            PORTA = i;

            /*
             * Delay of 1 second between counts
             */
            _delay_ms(1000);
        }
    }

    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. 4-bit Counter:
     *    - Uses 4 output pins (PA0–PA3)
     *    - Maximum count = 2^4 = 16 (0 to 15)
     *
     * 2. DDRA register:
     *    - DDRA controls direction of PORTA pins
     *    - Bit = 1 → Output
     *    - Bit = 0 → Input
     *    - DDRA |= 0x0F sets PA0–PA3 as outputs
     *
     * 3. Why uint8_t?
     *    - AVR supports 8-bit, 16-bit, etc.
     *    - uint4_t does NOT exist in C
     *    - uint8_t safely holds values 0–255
     *
     * 4. PORTA output:
     *    - PORTA = i sends binary value of i to pins
     *    - Example:
     *        i = 5  → 0101 on PA3–PA0
     *
     * 5. _delay_ms(1000):
     *    - Creates a visible 1-second delay
     *    - Requires correct F_CPU definition
     *
     * 6. Infinite loop:
     *    - Embedded programs run continuously
     *    - while(1) ensures counter never stops
     *
     * 7. Beginner Tip:
     *    - You can connect LEDs with resistors to PA0–PA3
     *    - Observe binary counting visually
     */
}
