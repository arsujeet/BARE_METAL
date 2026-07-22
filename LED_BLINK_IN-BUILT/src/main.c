#include <stdint.h>

/* RCC */
#define RCC_BASE        0x40021000UL
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

/* GPIOC */
#define GPIOC_BASE      0x40011000UL
#define GPIOC_CRH       (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR       (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))

void delay(volatile uint32_t count)
{
    while(count--);
}

int main(void)
{
    /* Enable GPIOC clock (IOPCEN bit = 4) */
    RCC_APB2ENR |= (1 << 4);

    /*
        Configure PC13 as:
        Output Push-Pull
        Max Speed = 2 MHz

        PC13 uses CRH bits [23:20]

        MODE13 = 10 (2 MHz)
        CNF13  = 00 (Push-Pull)

        => 0b0010 = 0x2
    */

    GPIOC_CRH &= ~(0xF << 20);   // Clear bits
    GPIOC_CRH |=  (0x2 << 20);   // Set output push-pull, 2MHz

    while (1)
    {
        GPIOC_ODR &= ~(1 << 13);   // LED ON (active low)
        delay(500000);

        GPIOC_ODR |= (1 << 13);    // LED OFF
        delay(500000);
    }
}