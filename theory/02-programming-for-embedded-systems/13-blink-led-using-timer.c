/*
 * Program: LED Blinking using Timer0 (Normal Mode)
 * MCU    : ATmega32
 *
 * Objective:
 *   Blink an LED connected to pin PB4 with a delay interval of 1 ms
 *   using Timer0 in Normal Mode.
 *
 * -------------------------------------------------------------
 * GIVEN DATA
 * -------------------------------------------------------------
 *
 * Clock frequency (F_CPU) = 16 MHz
 *
 * Required delay for LED toggle = 1 ms
 *
 * 1 ms = 1000 microseconds
 *
 * -------------------------------------------------------------
 * TIMER CLOCK CALCULATION
 * -------------------------------------------------------------
 *
 * Timer clock period:
 *
 *      Timing clock = 1 / F_CPU
 *
 *      = 1 / 16 MHz
 *      = 62.5 ns
 *
 * -------------------------------------------------------------
 * REQUIRED NUMBER OF TIMER COUNTS
 * -------------------------------------------------------------
 *
 *      Counts = Delay / Timing clock
 *
 *      = 1000 us / 62.5 ns
 *      = 16000 counts
 *
 * Timer0 capacity:
 *      Timer0 is an 8-bit timer
 *      It counts from 0 -> 255
 *
 *      Maximum counts = 256
 *
 * Since:
 *
 *      16000 > 256
 *
 * Timer0 cannot directly generate 1 ms delay.
 *
 * -------------------------------------------------------------
 * USING PRESCALER
 * -------------------------------------------------------------
 *
 * Choose prescaler = 64
 *
 * Effective counts required:
 *
 *      Counts = 16000 / 64
 *      Counts = 250
 *
 * Now:
 *
 *      250 < 256
 *
 * This fits within Timer0 capacity.
 *
 * -------------------------------------------------------------
 * TIMER INITIAL VALUE
 * -------------------------------------------------------------
 *
 * In Normal Mode timer counts from:
 *
 *      TCNT0 -> 255 -> overflow
 *
 * Required counts = 250
 *
 * Therefore starting value:
 *
 *      TCNT0 = 256 − 250
 *      TCNT0 = 6
 *
 *      Decimal = 6
 *      Hexadecimal = 0x06
 *
 * -------------------------------------------------------------
 * TIMER CONFIGURATION
 * -------------------------------------------------------------
 *
 *      TCNT0  = 0x06     -> Timer start value
 *
 *      TCCR0  = 0x03
 *
 *      0x03 = 00000011
 *
 *      CS02 CS01 CS00
 *       0    1    1
 *
 * Prescaler = 64
 *
*/

#define F_CPU 16000000UL      // Define CPU clock frequency (16 MHz)

#include <avr/io.h>           // AVR I/O register definitions


// -------------------------------------------------------------
// Function Prototype
// -------------------------------------------------------------
void Timer0Delay();


int main(void)
{
    // -------------------------------------------------------------
    // Step 1: Configure PB4 as OUTPUT
    // -------------------------------------------------------------
    /*
     * DDRB -> Data Direction Register for PORTB
     *
     * Bit value:
     *      1 -> Output
     *      0 -> Input
     *
     * (1 << PB4) shifts 1 to bit position of PB4.
     * This sets PB4 as an output pin.
    */

    DDRB |= (1 << PB4);


    // -------------------------------------------------------------
    // Step 2: Infinite loop
    // -------------------------------------------------------------
    while (1)
    {
        /*
         * Toggle PB4
         *
         * XOR operation toggles the bit:
         *
         *      0 -> 1
         *      1 -> 0
         *
         * This turns the LED ON and OFF.
        */

        PORTB ^= (1 << PB4);


        /*
         * Call Timer0 delay function
         * Generates approximately 1 ms delay
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
 *      Generate approximately 1 ms delay
 *      using Timer0 in Normal Mode.
 *
 * Working principle:
 *
 *      1. Load timer with initial value (6)
 *      2. Start timer with prescaler 64
 *      3. Wait for overflow flag (TOV0)
 *      4. Stop timer
 *      5. Clear overflow flag
 *
*/

void Timer0Delay()
{
    // -------------------------------------------------------------
    // Step 1: Load timer initial value
    // -------------------------------------------------------------
    /*
     * TCNT0 -> Timer Counter Register
     *
     * Timer starts counting from this value.
     *
     * Loading 0x06 ensures timer counts:
     *
     *      6 -> 255
     *
     * Which gives exactly 250 counts.
    */

    TCNT0 = 0x06;


    // -------------------------------------------------------------
    // Step 2: Start Timer0
    // -------------------------------------------------------------
    /*
     * TCCR0 -> Timer/Counter Control Register
     *
     * 0x03 = 00000011
     *
     * CS02 CS01 CS00
     *  0    1    1
     *
     * Prescaler = 64
    */

    TCCR0 = 0x03;


    // -------------------------------------------------------------
    // Step 3: Wait for timer overflow
    // -------------------------------------------------------------
    /*
     * TIFR -> Timer Interrupt Flag Register
     *
     * TOV0 -> Timer0 Overflow Flag
     *
     * When timer reaches:
     *
     *      255 -> overflow -> 0
     *
     * TOV0 flag becomes 1.
    */

    while ((TIFR & (1 << TOV0)) == 0);


    // -------------------------------------------------------------
    // Step 4: Stop timer
    // -------------------------------------------------------------

    TCCR0 = 0x00;


    // -------------------------------------------------------------
    // Step 5: Clear overflow flag
    // -------------------------------------------------------------
    /*
     * AVR special rule:
     *
     *      Writing 1 -> clears the flag
     *      Writing 0 -> no effect
     *
     * Therefore:
    */

    TIFR = (1 << TOV0);
}


/*
 * =================== KEY NOTES ===================
 *
 * 1. Timer0
 *    - 8-bit timer
 *    - Maximum count = 256
 *
 * 2. Prescaler
 *
 *    Prescaler divides system clock:
 *
 *    Timer frequency =
 *          F_CPU / Prescaler
 *
 *          = 16 MHz / 64
 *          = 250 kHz
 *
 * 3. Overflow Flag (TOV0)
 *
 *    Automatically set when:
 *
 *          TCNT0 -> 255 -> overflow
 *
 * 4. Clearing Flags
 *
 *    In AVR:
 *
 *          Write 1 -> Clear flag
 *          Write 0 -> No effect
 *
 *    Correct way:
 *
 *          TIFR = (1 << TOV0);
 *          TIFR |= (1 << TOV0); can also be used but is less efficient
 *
 * 5. LED Blinking
 *
 *    LED toggles every 1 ms.
 *
 *    Therefore full ON-OFF cycle = 2 ms
 *
*/