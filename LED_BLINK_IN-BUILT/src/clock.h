#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#include "gpio.h"
void clock_enable_gpio(GPIO_Port port);
void clock_disable_gpio(GPIO_Port port);

#endif