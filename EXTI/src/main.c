#include<stdint.h>
typedef struct{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
}gpio;
typedef  struct {
    volatile uint32_t  CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
}rcc;
typedef struct {
    volatile uint32_t EVCR;
    volatile uint32_t MAPR;
    volatile uint32_t EXTICR1;
    volatile uint32_t EXTICR2;
    volatile uint32_t EXTICR3;
    volatile uint32_t EXTICR4;
     uint32_t reser;
     volatile uint32_t MAPR2;
}afio;
typedef struct 
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
    
}exti;
typedef struct  
{
    volatile uint32_t ISER[2];
    uint32_t RESERVED0[30];
    
    volatile uint32_t ICER[2];
    uint32_t RESERVED1[30];

    volatile uint32_t ISPR[2];
    uint32_t RESERVED2[30];

    volatile uint32_t ICPR[2];
    uint32_t RESERVED3[30];

    volatile uint32_t IABR[2];
    uint32_t RESERVED4[64];

   volatile uint32_t IPR[60]; }nvic;
#define  gpioa_base 0x40010800UL
#define  gpiob_base 0x40010C00UL
#define  gpioc_base 0x40011000UL
#define rcc_base    0x40021000UL
#define afio_base    0x40010000UL
#define exti_base    0x40010400UL
#define NVIC_base 0xE000E100UL
#define GPIO_A ((gpio *)gpioa_base)
#define GPIO_B ((gpio *)gpiob_base)
#define GPIO_C ((gpio *)gpioc_base)
#define RCC    ((rcc *)rcc_base)
#define AFIO   ((afio *)afio_base)
#define EXTI    ((exti *)exti_base)
#define NVIC   ((nvic *)NVIC_base)

void EXTI0_IRQHandler(void){
    if(EXTI->PR & (1<<0)){
        GPIO_C->ODR ^=(1<<13);
        EXTI->PR |= (1<<0);
    }
}
int main(void){
    RCC->APB2ENR |= (1<<0) | (1<<2) | (1<<4);
    GPIO_C->CRH &= ~(0xF<<20) ;
    GPIO_C->CRH |= (0x2<<20) ;
    GPIO_A->CRL &= ~(0xF<<0);
    GPIO_A->CRL |=  (0x4<<0);
    AFIO->EXTICR1 &= ~(0xF<<0);
    AFIO->EXTICR1 |= (0x0<<0);
    EXTI->IMR |= (0x1<<0);
    EXTI->RTSR |= (0x1<<0);
    EXTI->FTSR &= ~(0x1<<0);
    NVIC->ISER[0]|=(1<<6);
    while(1){

    }
 
}


