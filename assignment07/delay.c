#include "delay.h"

void delay(uint32_t delayInMilliseconds)
{

    while(delayInMilliseconds > 0)
    {
        delayInMilliseconds--;
    }

}