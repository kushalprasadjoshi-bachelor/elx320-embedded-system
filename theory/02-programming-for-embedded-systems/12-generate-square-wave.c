/*
 * Program: Square Wave Generation using Timer0 (Normal Mode)
 * MCU    : ATmega32
 *
 * Objective:
 *   Generate a square wave with total period = 12.5 µs on pin PB3
 *   using Timer0 in Normal Mode.
 *
 * Given:
 *   Total period (T) = 12.5 µs
 *   Half period (delay) = T / 2 = 6.25 µs
 *
 * Clock Frequency:
 *   F_CPU = 8 MHz
 *
 * Timer clock period:
 *   Timer Tick = 1 / 8 MHz = 0.125 µs
 *
 * Required Timer Counts:
 *   counts = delay / timer_tick
 *   counts = 6.25 µs / 0.125 µs
 *   counts = 50
 *
 * Timer0 characteristics:
 *   Timer0 is an 8-bit timer
 *   It counts from 0 -> 255 (256 counts total)
 *
 * To generate only 50 counts before overflow:
 *
 *   Initial Value = 256 - 50
 *                 = 206
 *                 = 0xCE (hexadecimal)
 *
 * Timer Configuration:
 *   TCNT0 = 0xCE  -> Timer starts counting from 206
 *   TCCR0 = 0x01  -> Prescaler = 1 (No prescaling)
 */

#define F_CPU 8000000UL        // Define CPU clock frequency (8 MHz)

#include <avr/io.h>            // AVR register definitions

// -------------------------------------------------------------
// Function Prototype
// -------------------------------------------------------------
void Timer0Delay(void);


int main(void)
{
    // ---------------------------------------------------------
    // Step 1: Configure PB3 as OUTPUT
    // ---------------------------------------------------------
    /*
     * DDRB (Data Direction Register B)
     *
     * Bit = 1 -> Output
     * Bit = 0 -> Input
     *
     * (1 << PB3) shifts 1 to bit position of PB3
     * This sets PB3 as an output pin
     */

    DDRB |= (1 << PB3);


    // ---------------------------------------------------------
    // Step 2: Infinite loop
    // ---------------------------------------------------------
    while (1)
    {
        /*
         * Toggle PB3
         *
         * XOR operation flips the bit:
         * 0 -> 1
         * 1 -> 0
         *
         * This helps generate the square wave
         */

        PORTB ^= (1 << PB3);

        /*
         * Call delay function
         * This generates half-period delay (6.25 µs)
         */

        Timer0Delay();
    }

    return 0;
}


/*
 * -------------------------------------------------------------
 * Function: Timer0Delay
 *
 * Purpose:
 *   Generate ~6.25 µs delay using Timer0 in Normal Mode.
 *
 * Working:
 *   1. Load timer with initial value (206)
 *   2. Start timer with prescaler = 1
 *   3. Wait until overflow flag (TOV0) is set
 *   4. Stop timer
 *   5. Clear overflow flag
 * -------------------------------------------------------------
 */

void Timer0Delay(void)
{
    // ---------------------------------------------------------
    // Step 1: Load initial timer value
    // ---------------------------------------------------------
    /*
     * TCNT0 = Timer/Counter Register
     *
     * Loading 0xCE (206) ensures timer counts exactly 50 ticks
     * before overflowing.
     */

    TCNT0 = 0xCE;


    // ---------------------------------------------------------
    // Step 2: Start Timer0
    // ---------------------------------------------------------
    /*
     * TCCR0 = Timer/Counter Control Register
     *
     * 0x01 -> CS00 = 1
     *
     * Prescaler = 1
     * Timer runs at system clock (8 MHz)
     */

    TCCR0 = 0x01;


    // ---------------------------------------------------------
    // Step 3: Wait for timer overflow
    // ---------------------------------------------------------
    /*
     * TIFR = Timer Interrupt Flag Register
     *
     * TOV0 -> Timer0 Overflow Flag
     *
     * When TCNT0 counts from 255 -> 0,
     * overflow occurs and TOV0 becomes 1.
     */

    while ((TIFR & (1 << TOV0)) == 0);


    // ---------------------------------------------------------
    // Step 4: Stop the timer
    // ---------------------------------------------------------

    TCCR0 = 0x00;


    // ---------------------------------------------------------
    // Step 5: Clear overflow flag
    // ---------------------------------------------------------
    /*
     * AVR flag clearing rule:
     *
     * Writing '1' -> clears the flag
     * Writing '0' -> has no effect
     *
     * Therefore writing:
     *
     *     TIFR |= (1 <<TOV0); -> Clears TOV0 but may also clear 
     *               other flags that were already set (read-modify-write)
     * 
     *     TIFR = (1 << TOV0); -> Safely clears only TOV0 by 
     *                 writing 1 to that bit (W1C register)
     *
     * clears the overflow flag.
     */

    TIFR = (1 << TOV0);
}


/*
 * ======================= KEY NOTES =======================
 *
 * 1. Square Wave Generation
 *
 *    Each toggle produces half of the waveform.
 *
 *    Toggle -> delay -> toggle -> delay
 *
 *    Total Period = 2 × delay
 *                 = 2 × 6.25 µs
 *                 = 12.5 µs
 *
 * 2. Output Frequency
 *
 *    Frequency = 1 / Period
 *              = 1 / 12.5 µs
 *              = 80 kHz
 *
 * 3. Timer0 Overview
 *
 *    Timer0 is an 8-bit timer:
 *    Maximum count = 256
 *
 * 4. Prescaler
 *
 *    CS02 CS01 CS00
 *     0    0    1  -> Prescaler = 1
 *
 * 5. Overflow Flag (TOV0)
 *
 *    Automatically set when:
 *
 *    TCNT0 -> 255 -> overflow
 *
 * 6. Important AVR Concept
 *
 *    Interrupt flags are cleared by writing '1'.
 *
 *    Example:
 *
 *       TIFR = (1 << TOV0);
 *
 *    Writing '0' does nothing.
 *
 */