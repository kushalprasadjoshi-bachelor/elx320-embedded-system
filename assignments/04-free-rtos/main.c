#include <avr/io.h>
#include <util/delay.h>

#include "FreeRTOS.h"
#include "task.h"

/* LED pins */
#define LED1_PIN   PB0
#define LED2_PIN   PB1

static void vLed1Task(void *pvParameters)
{
    (void) pvParameters;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        PORTB ^= (1 << LED1_PIN);                 // Toggle LED1
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(500));
    }
}

static void vLed2Task(void *pvParameters)
{
    (void) pvParameters;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        PORTB ^= (1 << LED2_PIN);                 // Toggle LED2
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    /* Set PB0 and PB1 as output */
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN);

    /* Start with LEDs OFF */
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN));

    /* Create tasks */
    xTaskCreate(vLed1Task, "LED1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vLed2Task, "LED2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    /* Should never reach here */
    for (;;)
    {
    }
}