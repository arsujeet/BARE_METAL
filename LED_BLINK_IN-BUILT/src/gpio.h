#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum
{
    GPIO_INPUT = 0,
    GPIO_OUTPUT_PP,
    GPIO_OUTPUT_OD,
    GPIO_INPUT_PULLUP,
    GPIO_INPUT_PULLDOWN,
    GPIO_ANALOG
} GPIO_Mode;

typedef enum
{
    LOW = 0,
    HIGH = 1
} GPIO_State;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} GPIO_Pin;

typedef enum
{
    GPIO_A = 0,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E
} GPIO_Port;

void gpio_init(GPIO_Port port, GPIO_Pin pin, GPIO_Mode mode);

void gpio_write(GPIO_Port port, GPIO_Pin pin, GPIO_State state);

GPIO_State gpio_read(GPIO_Port port, GPIO_Pin pin);

void gpio_toggle(GPIO_Port port, GPIO_Pin pin);

#endif