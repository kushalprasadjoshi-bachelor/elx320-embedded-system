# Assignment 04 - Free RTOS Service

**Write a C program to blink two leds with different delays (500ms and 1000ms). Use services of FreeRTOS in the program.**

**FreeRTOS Configurations:**
```c
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCPU_CLOCK_HZ                      ( ( unsigned long ) 8000000 )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                    ( 5 )
#define configMINIMAL_STACK_SIZE                 ( ( unsigned short ) 85 )
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) 700 )
#define configMAX_TASK_NAME_LEN                 ( 8 )
#define configUSE_16_BIT_TICKS                  1
#define configUSE_MUTEXES                       0
#define configUSE_COUNTING_SEMAPHORES           0
#define configCHECK_FOR_STACK_OVERFLOW          0
#define configUSE_RECURSION                     0
#define configUSE_MALLOC_FAILED_HOOK            0

/* Optional but useful */
#define configUSE_TIME_SLICING                  1

/* Required by FreeRTOS */
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelete                     1

#endif
```

**Main Program:**
```c
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
```

---