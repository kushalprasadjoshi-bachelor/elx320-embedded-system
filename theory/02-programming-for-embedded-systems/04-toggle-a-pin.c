/*
 * Program: Toggle the 6th pin (PC5) of PORTC
 * MCU: ATmega32
 * Objective:
 *   Continuously toggle the 6th pin of PORTC (PC5) without affecting other pins.
 *   Useful for blinking a single LED connected to PC5.
 */

#include <avr/io.h>     // AVR register definitions
#include <stdint.h>     // For uint8_t data type

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure PORTC pin 5 (6th pin, 0-based) as output
    // -------------------------------------------------------------
    // DDRC = Data Direction Register for PORTC
    // 1 → output, 0 → input
    // DDRC |= (1 << PC5) sets only PC5 as output, leaves others unchanged
    DDRC |= (1 << PC5);

    // -------------------------------------------------------------
    // Step 2: Infinite loop to toggle PC5
    // -------------------------------------------------------------
    while (1) {

        // Toggle only PC5 using XOR
        // PORTC ^= (1 << PC5) flips the current state of PC5
        // 0 → 1, 1 → 0
        PORTC ^= (1 << PC5);

        // Note: No delay is used, toggling happens extremely fast
        // For LED visualization, add _delay_ms(500);
    }

    // Program never reaches this line
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Pin numbering:
     *    - AVR pins are 0-based
     *    - 6th pin → bit 5 (PC5)
     *
     * 2. DDRC:
     *    - Configure pins as input (0) or output (1)
     *    - DDRC |= (1 << PC5) sets PC5 as output without affecting other pins
     *
     * 3. PORTC toggle:
     *    - PORTC ^= (1 << PC5) toggles only PC5
     *    - Using ~PORTC would invert all pins → not desired
     *
     * 4. Infinite loop:
     *    - Embedded programs usually run continuously
     *    - while(1) ensures PC5 toggles endlessly
     *
     * 5. Optional delay:
     *    - Include:
     *        #define F_CPU 8000000UL
     *        #include <util/delay.h>
     *        _delay_ms(500);
     *    - Makes LED toggling human-visible
     *
     * 6. Practical usage:
     *    - Single LED blink
     *    - Understanding bitwise operations in embedded C
     */
}
