/*
 * Program: Output values from 0x00 to 0xFF on PORTC
 * MCU: ATmega32
 * Objective:
 *   To send all possible 8-bit values (0 to 255) sequentially to PORTC.
 *   This is useful for testing LEDs, DACs, or understanding binary counting.
 */

#include <avr/io.h>    // AVR register definitions
#include <stdint.h>    // For uint16_t data type

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure PORTC as output
    // -------------------------------------------------------------
    // DDRC = 0xFF -> All pins of PORTC are set as output
    DDRC = 0xFF;

    // -------------------------------------------------------------
    // Step 2: Send values from 0x00 to 0xFF to PORTC
    // -------------------------------------------------------------
    // uint8_t can hold values from 0 to 255 (8-bit unsigned integer)
    for (uint16_t p = 0; p < 256; p++) {
        // Loop iterations can be defined in hexadecimal (0x...)(0X...), decimal (...), oct (0...) and binary (0b...)(0B...)

        // Output the current value of 'p' to PORTC
        PORTC = p;

        // No delay is used here, so changes happen very fast
        // LEDs connected to PORTC may appear always ON or flickering
    }

    // Program ends here (in real embedded systems, usually while(1) is used)
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. DDRC:
     *    - Data Direction Register for PORTC
     *    - 1 = output, 0 = input
     *    - DDRC = 0xFF makes all PORTC pins outputs
     *
     * 2. PORTC:
     *    - Used to send output data to PORTC pins
     *    - Each bit of PORTC controls one pin
     *
     * 3. uint8_t:
     *    - Unsigned 8-bit data type
     *    - Range: 0 to 255
     *    - Requires #include <stdint.h>
     *
     * 4. for-loop explanation:
     *    - Starts at 0 (0x00)
     *    - Ends at 255 (0xFF)
     *    - Each iteration increases value by 1
     *
     * 5. Important embedded concept:
     *    - Using p <= 255 with uint8_t causes overflow and infinite loop
     *    - Correct condition is p < 256
     *
     * 6. Observation:
     *    - Without delay, output changes very fast
     *    - To visualize counting on LEDs, add _delay_ms()
     *
     * 7. Practical usage:
     *    - Testing LED connections
     *    - Understanding binary counting
     *    - Checking PORT functionality
     */
}
