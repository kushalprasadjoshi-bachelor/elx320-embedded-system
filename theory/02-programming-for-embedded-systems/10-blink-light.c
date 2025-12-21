/*
 * Program: Blink LEDs on PORTA
 * MCU: ATmega32
 * Objective:
 *   - Demonstrate three different methods to blink LEDs
 *   - Method 1: Alternate pattern assignment
 *   - Method 2: XOR toggling
 *   - Method 3: Bitwise NOT toggling
 */

#define F_CPU 1000000UL      // Define CPU clock frequency (1 MHz)
                            // MUST be defined before including delay library

#include <avr/io.h>
#include <util/delay.h>   // For _delay_ms()

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure PORTA as output
    // -------------------------------------------------------------
    DDRA = 0xFF;  // All pins of PORTA as output

    // -------------------------------------------------------------
    // Method 1: Alternate pattern assignment
    // -------------------------------------------------------------
    while (1) {
        PORTA = 0b01010101;  // Set alternating LEDs ON/OFF
        _delay_ms(500);      // Wait 500ms
        PORTA = 0b10101010;  // Invert pattern
        _delay_ms(500);      // Wait 500ms
    }

    /*
    // -------------------------------------------------------------
    // Method 2: XOR toggling
    // -------------------------------------------------------------
    PORTA = 0b01010101;  // Initial pattern
    while (1) {
        _delay_ms(500);     // Wait 500ms
        PORTA ^= 0xFF;      // XOR with 0xFF toggles all bits
    }
    */

    /*
    // -------------------------------------------------------------
    // Method 3: Bitwise NOT toggling
    // -------------------------------------------------------------
    while (1) {
        PORTA = ~PORTA;     // Invert all bits of PORTA
        _delay_ms(500);     // Wait 500ms
    }
    */

    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. DDR register:
     *    - DDRA = 0xFF → all pins of PORTA are outputs
     *
     * 2. Method 1: Alternate pattern assignment
     *    - Assign specific binary patterns to PORTA
     *    - 0b01010101 → LEDs alternate ON/OFF
     *    - 0b10101010 → inverted pattern
     *
     * 3. Method 2: XOR toggling
     *    - PORTA ^= 0xFF flips all bits
     *    - Start with an initial pattern, then XOR in each iteration
     *
     * 4. Method 3: Bitwise NOT toggling
     *    - PORTA = ~PORTA also flips all bits
     *    - Simpler but works the same as XOR
     *
     * 5. _delay_ms():
     *    - Provides visible delay for LED blinking
     *    - Ensure F_CPU is defined if needed
     *
     * 6. Infinite loop:
     *    - Embedded programs run continuously
     *    - while(1) ensures LEDs keep blinking
     *
     * 7. Beginner tip:
     *    - You can choose any of the three methods depending on preference
     *    - XOR and NOT methods are useful for dynamic patterns
     */
}
