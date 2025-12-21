/*
 * Program: Check if a number from PORTA is even or odd
 * MCU: ATmega32
 * Objective:
 *   - Read an 8-bit number from PORTA
 *   - If even → turn ON PB0, PB1 OFF
 *   - If odd  → turn ON PB1, PB0 OFF
 */

#include <avr/io.h>
#include <stdint.h>

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure DDR registers
    // -------------------------------------------------------------
    DDRA = 0x00;               // PORTA as input
    DDRB |= (1 << PB0) | (1 << PB1); // PB0 and PB1 as outputs

    // -------------------------------------------------------------
    // Step 2: Infinite loop to continuously read number and update LEDs
    // -------------------------------------------------------------
    while (1) {

        // Read input from PORTA
        uint8_t portA_input = PINA;

        // Mask only LSB (PA0) to check even/odd
        // If LSB = 0 → even, LSB = 1 → odd
        uint8_t lsb = portA_input & (1 << PA0); // portA_input & (1 << 0) can be used because PB0 = 0

        if (lsb == 0) {
            // Number is even
            PORTB |= (1 << PB0);    // Turn ON PB0
            PORTB &= ~(1 << PB1);   // Turn OFF PB1
        } else {
            // Number is odd
            PORTB |= (1 << PB1);    // Turn ON PB1
            PORTB &= ~(1 << PB0);   // Turn OFF PB0
        }
    }

    // Program never reaches this line
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Even/Odd check:
     *    - Only the least significant bit (LSB) determines parity
     *    - LSB = 0 → even, LSB = 1 → odd
     *
     * 2. Bit masking:
     *    - lsb = portA_input & (1 << PA0)
     *    - Isolates only the least significant bit
     *
     * 3. DDR registers:
     *    - DDRA = 0x00 → PORTA as input
     *    - DDRB |= (1 << PB0) | (1 << PB1) → PB0 & PB1 as output
     *
     * 4. PORTB manipulation:
     *    - PORTB |= (1 << PBx) → set bit PBx
     *    - PORTB &= ~(1 << PBx) → clear bit PBx
     *    - Ensures only the intended LED is ON at a time
     *
     * 5. Infinite loop:
     *    - Ensures continuous monitoring of PORTA
     *
     * 6. Practical usage:
     *    - Turn on different LEDs depending on even/odd number input
     *    - Simple demonstration of bitwise operations in embedded C
     *
     * 7. Beginner tip:
     *    - Always clear previous output bits when toggling LEDs
     *    - Helps prevent unwanted multiple LEDs being ON simultaneously
     */
}
