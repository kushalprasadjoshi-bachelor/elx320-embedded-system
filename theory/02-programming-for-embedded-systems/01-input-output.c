/*
 * Program: Mirror input from PORTA to PORTB
 * MCU: ATmega32
 * Objective: Read the state of input pins on PORTA and output the same value on PORTB
 * 
 * Explanation:
 * - PORTA is configured as input
 * - PORTB is configured as output
 * - In an infinite loop, the program continuously reads PORTA
 *   and writes the same value to PORTB, effectively "mirroring" the input
 */

#include <avr/io.h>    // AVR microcontroller register definitions
#include <stdint.h>    // For uint8_t (unsigned 8-bit data type)

int main(void) {
    // -------------------------------------------------------------
    // Step 1: Configure Data Direction Registers (DDR)
    // Values can be assigned in hexadecimal (0x...)(0X...), decimal (...), oct (0...) and binary (0b...)(0B...)
    // -------------------------------------------------------------
    // DDRA = 0x00 -> All pins of PORTA are set as input (0 = input)
    DDRA = 0x00; 

    // DDRB = 0xFF -> All pins of PORTB are set as output (1 = output)
    DDRB = 0xFF;

    // -------------------------------------------------------------
    // Step 2: Main loop
    // -------------------------------------------------------------
    // The microcontroller will continuously execute this loop
    while (1) {
        // Read all 8 pins of PORTA and store in variable 'a'
        // PINA register holds the current logic level of PORTA pins
        uint8_t a = PINA;

        // Output the value of 'a' to PORTB
        // This mirrors the input pins of PORTA to the output pins of PORTB
        PORTB = a;

        // Note: No delay is used, so PORTB updates as fast as the MCU can read PORTA
    }

    // Return statement will never be reached
    return 0;

    /* 
     * =================== KEY NOTES ===================
     * 1. Registers used:
     *    - DDRA, DDRB: Configure pins as input (0) or output (1)
     *    - PINA: Reads the current logic level of PORTA pins
     *    - PORTB: Writes output to PORTB pins
     *
     * 2. uint8_t:
     *    - Unsigned 8-bit integer (0–255)
     *    - Requires #include <stdint.h>
     *
     * 3. Infinite loop (while(1)):
     *    - Embedded programs usually run forever
     *    - Without it, MCU may exit main(), causing undefined behavior
     *
     * 4. Behavior:
     *    - Each pin on PORTA is mirrored to corresponding pin on PORTB
     *    - If a switch is pressed on PORTA.0, the LED on PORTB.0 lights up
     *
     * 5. Notes for beginners:
     *    - Always configure DDR registers before using PORT or PIN 
     *    - Avoid leaving microcontroller pins floating; use pull-up resistors if needed
     *    - This program does not include delays; adding _delay_ms() can make LED changes visible
     */
}
