/*
 * Program: Read PA0 and PA1 and send corresponding ASCII character to PORTB
 * MCU: ATmega32
 * Objective:
 *   - PA0 PA1 = 00 → send '0' to PORTB
 *   - PA0 PA1 = 01 → send '1' to PORTB
 *   - PA0 PA1 = 10 → send '2' to PORTB
 *   - PA0 PA1 = 11 → send '3' to PORTB
 */

#include <avr/io.h>
#include <stdint.h>

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure DDR registers
    // -------------------------------------------------------------
    DDRA &= ~((1 << PA0) | (1 << PA1));   // PA0 and PA1 as input
    DDRB = 0xFF;                          // PORTB as output

    // -------------------------------------------------------------
    // Step 2: Infinite loop to continuously read inputs
    // -------------------------------------------------------------
    while (1) {
        // Read current state of PORTA
        uint8_t portA_input = PINA;

        // Mask only PA0 and PA1
        // (1 << PA0) | (1 << PA1) = 0b00000011
        uint8_t masked_input = portA_input & ((1 << PA0) | (1 << PA1)); // portA_input & ((1 << 0) | (1 << 1)) can also be used

        // Conditional output based on input value
        // Simply decimal values 0, 1, 2, 3 can be used in the cases
        // Also "case (1 << PA0) | (1 << PA1)" can be used (for 1 1 in this case)
        switch (masked_input) {
            case 0b00:  // PA1=0, PA0=0
                PORTB = '0';
                break;
            case 0b01:  // PA1=0, PA0=1
                PORTB = '1';
                break;
            case 0b10:  // PA1=1, PA0=0
                PORTB = '2';
                break;
            case 0b11:  // PA1=1, PA0=1
                PORTB = '3';
                break;
        }
    }

    // Program never reaches here
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Pin numbering:
     *    - AVR pins are 0-based
     *    - PA0 = bit 0, PA1 = bit 1
     *
     * 2. DDR registers:
     *    - DDRA &= ~((1 << PA0) | (1 << PA1)) → configure as input
     *    - DDRB = 0xFF → configure PORTB as output
     *
     * 3. Masking:
     *    - masked_input = portA_input & 0b00000011
     *    - Isolates PA0 and PA1
     *
     * 4. Logic mapping:
     *    - 0b00 → '0'
     *    - 0b01 → '1'
     *    - 0b10 → '2'
     *    - 0b11 → '3'
     *
     * 5. Infinite loop:
     *    - Ensures MCU continuously monitors PA0 and PA1
     *
     * 6. Practical usage:
     *    - Binary-to-ASCII conversion for 2-bit input
     *    - Display on LEDs or digital output
     *
     * 7. Beginner tip:
     *    - Use switch-case for readability when multiple input combinations
     *    - Always mask input pins to avoid affecting other bits
     */
}
