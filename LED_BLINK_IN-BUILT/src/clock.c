#include "clock.h"
#include "registers.h"

void clock_enable_gpio(GPIO_Port port)
{
    switch (port)
    {
        case GPIO_A:
            RCC_APB2ENR |= (1 << 2);
            break;

        case GPIO_B:
            RCC_APB2ENR |= (1 << 3);
            break;

        case GPIO_C:
            RCC_APB2ENR |= (1 << 4);
            break;

        default:
            break;
    }
}

void clock_disable_gpio(GPIO_Port port)
{
    switch (port)
    {
        case GPIO_A:
            RCC_APB2ENR &= ~(1 << 2);
            break;

        case GPIO_B:
            RCC_APB2ENR &= ~(1 << 3);
            break;

        case GPIO_C:
            RCC_APB2ENR &= ~(1 << 4);
            break;

        default:
            break;
    }
}