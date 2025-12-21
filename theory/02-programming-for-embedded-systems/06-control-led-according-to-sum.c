/*
 * Program: Sum two numbers from PORTA and PORTB, control LED on PC3
 * MCU: ATmega32
 * Objective:
 *   - Read 8-bit numbers from PORTA and PORTB
 *   - Find their sum (signed)
 *   - Turn ON LED on PC3 if result is negative, OFF otherwise
 */

#include <avr/io.h>     // AVR register definitions
#include <stdint.h>     // For int8_t and int16_t data types

int main(void) {

    // -------------------------------------------------------------
    // Step 1: Configure Data Direction Registers
    // -------------------------------------------------------------
    // DDRA = 0x00 -> PORTA as input
    DDRA = 0x00;

    // DDRB = 0x00 -> PORTB as input
    DDRB = 0x00;

    // DDRC |= (1 << PC3) -> PC3 as output for LED
    DDRC |= (1 << PC3);

    // -------------------------------------------------------------
    // Step 2: Infinite loop to continuously read inputs and update LED
    // -------------------------------------------------------------
    while (1)
    {
        // Read signed 8-bit input from PORTA
        int8_t portA_input = PINA;

        // Read signed 8-bit input from PORTB
        int8_t portB_input = PINB;

        // Calculate sum (16-bit to avoid overflow)
        int16_t sum = portA_input + portB_input;

        // Control LED on PC3
        if (sum < 0)
        {
            // Turn ON LED if sum is negative
            PORTC |= (1 << PC3);
        }
        else
        {
            // Turn OFF LED if sum is zero or positive
            PORTC &= ~(1 << PC3);
        }
    }

    // Program never reaches this line
    return 0;

    /*
     * =================== KEY NOTES ===================
     *
     * 1. Registers used:
     *    - DDRA, DDRB: Configure PORTA and PORTB as input
     *    - DDRC: Configure PORTC as output (LED)
     *    - PINA, PINB: Read input from PORTA and PORTB
     *    - PORTC: Control LED on PC3
     *
     * 2. Data types:
     *    - int8_t: Signed 8-bit (-128 to 127)
     *    - int16_t: Signed 16-bit to store sum without overflow
     *
     * 3. Infinite loop:
     *    - Ensures continuous reading of input and LED update
     *
     * 4. Bit manipulation:
     *    - PORTC |= (1 << PC3) → Turn ON LED
     *    - PORTC &= ~(1 << PC3) → Turn OFF LED
     *
     * 5. Assumptions:
     *    - Inputs on PORTA and PORTB represent signed 8-bit numbers
     *    - If inputs are unsigned, negative results cannot occur
     *
     * 6. Practical use:
     *    - Monitor sum of two digital signals
     *    - LED indicates negative result
     */
}
