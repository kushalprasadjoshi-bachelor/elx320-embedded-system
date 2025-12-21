/*
 * Program: Turn ON 2nd pin (PD1) and OFF 5th pin (PD4) of PORTD
 * MCU: ATmega32
 * Objective:
 *   Set PD1 HIGH and PD4 LOW while keeping other pins unchanged.
 *   Useful for controlling LEDs or digital outputs.
 */

#include <avr/io.h>     // AVR register definitions
#include <stdint.h>     // For uint8_t data type

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure PD1 and PD4 as outputs
    // -------------------------------------------------------------
    // DDRD = Data Direction Register for PORTD
    // 1 → output, 0 → input
    // DDRD |= (1 << PD1) | (1 << PD4) sets PD1 and PD4 as outputs
    DDRD |= (1 << PD1) | (1 << PD4);

    // -------------------------------------------------------------
    // Step 2: Infinite loop to maintain outputs
    // -------------------------------------------------------------
    while (1) {
        // Turn ON PD1 (2nd pin)
        PORTD |= (1 << PD1);

        // Turn OFF PD4 (5th pin)
        PORTD &= ~(1 << PD4);

        // Note: Other pins remain unaffected
        // No delay is required unless you want to toggle or blink pins
    }

    // Program never reaches this line
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Pin numbering:
     *    - AVR pins are 0-based
     *    - 2nd pin → PD1
     *    - 5th pin → PD4
     *
     * 2. DDRD:
     *    - Sets pins as input (0) or output (1)
     *    - DDRD |= (1 << PD1) | (1 << PD4) sets PD1 and PD4 as outputs
     *
     * 3. PORTD:
     *    - PORTD |= (1 << PD1) → Sets PD1 HIGH
     *    - PORTD &= ~(1 << PD4) → Sets PD4 LOW
     *    - Other pins remain unaffected
     *
     * 4. Infinite loop:
     *    - Ensures MCU continuously holds the output state
     *
     * 5. Practical usage:
     *    - Turning LEDs ON/OFF
     *    - Controlling external devices
     *
     * 6. Beginner tip:
     *    - Always wrap embedded output programs in while(1)
     *    - Avoid writing to all pins unless intended
     */
}
