/*
 * Program: 1-Second Square Wave on LED using Timer0 (Normal Mode)
 * MCU    : ATmega32
 *
 * Objective:
 *   Blink an LED connected to PB4 with a square wave of 1-second period
 *   using Timer0 in Normal Mode.
 *
 * -------------------------------------------------------------
 * GIVEN DATA
 * -------------------------------------------------------------
 *
 * Clock frequency (F_CPU) = 16 MHz
 *
 * Required square wave period = 1 s
 *
 * Therefore, delay for toggle = 1 s / 2
 *                            = 0.5 s = 500 ms = 500,000 microseconds
 *
 * -------------------------------------------------------------
 * TIMER CLOCK CALCULATION
 * -------------------------------------------------------------
 *
 * Timer clock period:
 *
 *      Timer tick = 1 / F_CPU
 *                 = 1 / 16 MHz
 *                 = 62.5 ns = 0.0625 µs
 *
 * Total counts required to generate 500 ms delay:
 *
 *      Counts = Delay / Timer tick
 *             = 500,000 µs / 0.0625 µs
 *             = 8,000,000 counts
 *
 * Timer0 is 8-bit -> max count = 256
 *
 * Therefore, prescaler is required.
 *
 * Using prescaler = 1024:
 *
 *      Counts with prescaler = 8,000,000 / 1024
 *                            ≈ 7812.5 ~ 7813 counts
 *
 * This is still > 256 -> use internal loop.
 *
 * Total iterations of full 8-bit timer:
 *
 *      Iterations = 7813 / 256
 *                 ≈ 30
 *
 * Remaining counts:
 *
 *      Remaining counts = 7813 − (30 * 256)
 *                       = 7813 − 7680
 *                       = 133
 *
 * Initial value to load for remaining counts:
 *
 *      TCNT0 = 256 − 133
 *             = 123 = 0x7B
 *
 * Timer configuration:
 *
 *      Prescaler = 1024 -> TCCR0 = 0x05
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>   // For uint8_t type

// -------------------------------------------------------------
// Function Prototype
// -------------------------------------------------------------
void Timer0Delay(void);

int main(void)
{
    // ---------------------------------------------------------
    // Step 1: Configure PB4 as OUTPUT
    // ---------------------------------------------------------
    DDRB |= (1 << PB4);

    // ---------------------------------------------------------
    // Step 2: Infinite loop
    // ---------------------------------------------------------
    while (1)
    {
        // Toggle LED
        PORTB ^= (1 << PB4);

        // Generate 500 ms delay (half period)
        Timer0Delay();
    }

    return 0;
}


/*
 * -------------------------------------------------------------
 * Function: Timer0Delay
 *
 * Purpose:
 *   Generate approximately 500 ms delay using Timer0 in Normal Mode
 *   with prescaler 1024 and internal loop for multiple overflows.
 *
 * Working principle:
 *
 *   1. Run 30 full 8-bit overflows:
 *      TCNT0 = 0 -> 255, 30 iterations
 *
 *   2. Run one partial overflow with 133 counts:
 *      TCNT0 = 123 -> 255
 *
 *   3. Each overflow toggles TOV0 flag
 *      which is cleared after each iteration.
 * -------------------------------------------------------------
 */
void Timer0Delay(void)
{
    uint8_t i;

    // ---------------------------------------------------------
    // Step 1: Loop for 30 full 8-bit overflows
    // ---------------------------------------------------------
    for (i = 0; i < 30; i++)
    {
        TCNT0 = 0;        // Start from 0
        TCCR0 = 0x05;     // Start Timer0, prescaler 1024

        while ((TIFR & (1 << TOV0)) == 0);  // Wait for overflow

        TCCR0 = 0x00;     // Stop timer
        TIFR = (1 << TOV0); // Clear overflow flag
    }

    // ---------------------------------------------------------
    // Step 2: One partial overflow for remaining counts
    // ---------------------------------------------------------
    TCNT0 = 0x7B;         // 123 decimal -> 133 counts
    TCCR0 = 0x05;         // Start timer, prescaler 1024

    while ((TIFR & (1 << TOV0)) == 0);  // Wait for overflow

    TCCR0 = 0x00;         // Stop timer
    TIFR = (1 << TOV0);   // Clear overflow flag
}

/*
 * ======================= KEY NOTES =======================
 *
 * 1. Timer0
 *    - 8-bit timer
 *    - Max count = 256
 *
 * 2. Prescaler
 *    - Divides system clock to reduce timer counts
 *    - Here: 1024 -> 16 MHz / 1024 = 15625 Hz timer frequency
 *
 * 3. Internal Loop
 *    - Because 500 ms requires > 256 counts
 *    - Use loop for multiple overflows
 *
 * 4. Overflow Flag (TOV0)
 *    - Set when TCNT0 rolls from 255 -> 0
 *    - Must clear after each iteration:
 *          TIFR = (1 << TOV0);
 *
 * 5. LED Blinking
 *    - Each Timer0Delay() generates 500 ms delay
 *    - LED toggles -> full period = 1 s
 */