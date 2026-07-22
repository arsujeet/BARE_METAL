
#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

/* ============================
   RCC Registers
   ============================ */

#define RCC_BASE        0x40021000UL

#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

/* ============================
   GPIO Base Addresses
   ============================ */

#define GPIOA_BASE      0x40010800UL
#define GPIOB_BASE      0x40010C00UL
#define GPIOC_BASE      0x40011000UL

/* ============================
   GPIO Register Offsets
   ============================ */

#define GPIO_CRL_OFFSET     0x00
#define GPIO_CRH_OFFSET     0x04
#define GPIO_IDR_OFFSET     0x08
#define GPIO_ODR_OFFSET     0x0C
#define GPIO_BSRR_OFFSET    0x10
#define GPIO_BRR_OFFSET     0x14
#define GPIO_LCKR_OFFSET    0x18

/* ============================
   GPIOA Registers
   ============================ */

#define GPIOA_CRL   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_CRL_OFFSET))
#define GPIOA_CRH   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_CRH_OFFSET))
#define GPIOA_IDR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_IDR_OFFSET))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_ODR_OFFSET))
#define GPIOA_BSRR  (*(volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR_OFFSET))
#define GPIOA_BRR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR_OFFSET))

/* ============================
   GPIOB Registers
   ============================ */

#define GPIOB_CRL   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_CRL_OFFSET))
#define GPIOB_CRH   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_CRH_OFFSET))
#define GPIOB_IDR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_IDR_OFFSET))
#define GPIOB_ODR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR_OFFSET))
#define GPIOB_BSRR  (*(volatile uint32_t *)(GPIOB_BASE + GPIO_BSRR_OFFSET))
#define GPIOB_BRR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_BRR_OFFSET))

/* ============================
   GPIOC Registers
   ============================ */

#define GPIOC_CRL   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_CRL_OFFSET))
#define GPIOC_CRH   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_CRH_OFFSET))
#define GPIOC_IDR   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_IDR_OFFSET))
#define GPIOC_ODR   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_ODR_OFFSET))
#define GPIOC_BSRR  (*(volatile uint32_t *)(GPIOC_BASE + GPIO_BSRR_OFFSET))
#define GPIOC_BRR   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_BRR_OFFSET))

#endif