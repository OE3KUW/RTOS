/******************************************************************
                        Simple State Machine
                                                    қuran dez 2022
******************************************************************/
#include <Arduino.h>

// RTOS not used in this version:

// structs and types
typedef struct message MESSAGE;
struct message
{
    int x;
};
static MESSAGE m, n;

// TaskFunctions:
static void taskFuncA(void * arg)
{
    MESSAGE * myMesPointer = (MESSAGE*) arg;
    printf("\ntask function A!!! message: %d\n", myMesPointer->x);
    for(;;)
    {
        printf("a");
        delay(50);  // for demonstration only :-) 
    }
}

static void taskFuncB(void * arg)
{
    MESSAGE * myMesPointer = (MESSAGE*) arg;
    printf("\ntask function B! message: %d\n", myMesPointer->x);
    for(;;)
    {
        printf("b");
        delay(100);
    }
}

void setup() 
{
    int app_cpu = 0;  
  
    m.x = 7;     // for RTOS
    n.x = 100;   // for RTOS

    // RTOS:
    app_cpu = xPortGetCoreID();
  
    printf("app_cpu is %d\n", app_cpu);
    xTaskCreatePinnedToCore (taskFuncA, "task Function A", 2048, &m, 1, NULL, app_cpu );  
    xTaskCreatePinnedToCore (taskFuncB, "task Function B", 2048, &n, 1, NULL, app_cpu );
}

void loop() 
{

}