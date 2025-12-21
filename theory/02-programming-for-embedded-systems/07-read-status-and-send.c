/*
 * Program: Read 4th pin (PC3) of PORTC and send 0x10 accordingly
 * MCU: ATmega32
 * Objective:
 *   - If PC3 = 1 → send 0x10 to PORTA
 *   - If PC3 = 0 → send 0x10 to PORTB
 */

#include <avr/io.h>
#include <stdint.h>

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure DDR registers
    // -------------------------------------------------------------
    DDRA = 0xFF;             // PORTA as output
    DDRB = 0xFF;             // PORTB as output
    DDRC &= ~(1 << PC3);     // PC3 as input (4th pin)

    uint8_t data = 0x10;     // Data to send based on input

    // -------------------------------------------------------------
    // Step 2: Infinite loop to continuously check PC3
    // -------------------------------------------------------------
    while (1) {

        // Read current state of PORTC
        uint8_t portC_input = PINC;

        // Following method can be used but not convinent
        // 1. if (portC_input & (1 << 3)) {code} // Since value of PC3 is 3

        // Mask only PC3 (4th pin)
        // 1 << PC3 = 1 << 3 = 0b00001000
        // This isolates only bit 3 of PINC
        uint8_t masked_input = portC_input & (1 << PC3);

        // Conditional output
        if (masked_input) {
            // If PC3 is HIGH (1) → send 0x10 to PORTA
            PORTA = data;
        } else {
            // If PC3 is LOW (0) → send 0x10 to PORTB
            PORTB = data;
        }
    }

    // Program never reaches this line
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Pin numbering:
     *    - 0-based: 4th pin → PC3
     *    - 4th pin → PC3 (symbolic name)
     *
     * 2. DDRC:
     *    - DDRC &= ~(1 << PC3) → PC3 configured as input
     *    - DDRA and DDRB = 0xFF → all pins as output
     *
     * 3. PINC:
     *    - Read the logic level of PORTC pins
     *    - Mask with (1 << PC3) to get only 4th pin
     *
     * 4. Masking explanation:
     *    - 1 << PC3 → 0b00001000
     *    - portC_input & (1 << PC3) isolates only the 4th pin
     *    - Result is zero if pin is LOW, non-zero if pin is HIGH
     * 
     * 5. PORTA / PORTB:
     *    - Send 0x10 based on PC3 input
     *
     * 6. Infinite loop:
     *    - Ensures continuous monitoring of PC3
     *
     * 7. Practical usage:
     *    - Conditional control of outputs based on input pin
     *    - Useful for switches, sensors, or status indicators
     *
     * 8. Beginner tip:
     *    - Always mask input pins to avoid affecting other bits
     *    - Ensure DDR is correctly set for input/output before use
     */
}
