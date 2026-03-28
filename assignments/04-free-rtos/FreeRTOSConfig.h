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