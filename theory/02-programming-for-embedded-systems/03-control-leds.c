/*
 * Program: Control two LEDs on PORTB using input from PORTD
 * MCU: ATmega32
 * Objective:
 *   Control LEDs connected to PB3 and PB6 using corresponding inputs from PORTD.
 *   Other PORTB pins must remain OFF and not float.
 */

#include <avr/io.h>     // AVR register definitions
#include <stdint.h>     // For uint8_t data type

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure Data Direction Registers
    // -------------------------------------------------------------
    // DDRD = 0x00 -> All PORTD pins are configured as input
    DDRD = 0x00;

    // DDRB = 0xFF -> All PORTB pins are configured as output
    DDRB = 0xFF;

    // -------------------------------------------------------------
    // Step 2: Infinite loop
    // -------------------------------------------------------------
    while (1)
    {
        // Read the current input value from PORTD
        uint8_t portD_input = PIND;

        // Mask only bit 3 and bit 6 (0b01001000 = 0x48)
        // This ensures only required bits are used
        uint8_t masked_input = portD_input & 0x48;

        // Send masked input to PORTB
        // PB3 and PB6 will reflect input state
        // Other PORTB pins remain LOW
        PORTB = masked_input;
    }

    // This line is never reached
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Problem with original logic:
     *    - Writing PORTB = PIND copies all 8 bits
     *    - This unintentionally drives unused PORTB pins
     *    - Causes floating or unwanted behavior
     *
     * 2. Masking:
     *    - Masking allows selective control of bits
     *    - input & 0x48 keeps only bit 3 and bit 6
     *
     * 3. Binary representation of mask:
     *    - 0x48 = 0b01001000
     *      bit 6 → PB6 LED
     *      bit 3 → PB3 LED
     *
     * 4. Registers used:
     *    - DDRD: Configure PORTD as input
     *    - PIND: Read input from PORTD
     *    - DDRB: Configure PORTB as output
     *    - PORTB: Drive LEDs
     *
     * 5. Why while(1)?
     *    - Embedded systems run continuously
     *    - Inputs must be monitored repeatedly
     *
     * 6. Hardware behavior:
     *    - If PD3 is HIGH → LED on PB3 turns ON
     *    - If PD6 is HIGH → LED on PB6 turns ON
     *    - All other PORTB pins stay OFF
     *
     * 7. Beginner tip:
     *    - Always mask bits when controlling selected pins
     *    - Never write entire PORT unless all pins are intended to be used
     */
}
