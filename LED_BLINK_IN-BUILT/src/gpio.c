#include "gpio.h"
#include "registers.h"

void gpio_init(GPIO_Port port, GPIO_Pin pin, GPIO_Mode mode)
{
    /* Implement later */
}

void gpio_write(GPIO_Port port, GPIO_Pin pin, GPIO_State state)
{
    /* Implement later */
}

GPIO_State gpio_read(GPIO_Port port, GPIO_Pin pin)
{
    return LOW;
}

void gpio_toggle(GPIO_Port port, GPIO_Pin pin)
{
    if (port == GPIO_C && pin == PIN13)
    {
        GPIOC_ODR ^= (1 << 13);
    }

    if (port == GPIO_A && pin == PIN0)
    {
        GPIOA_ODR ^= (1 << 0);
    }
}