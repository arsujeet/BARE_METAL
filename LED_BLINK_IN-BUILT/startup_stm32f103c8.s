.syntax unified
.cpu cortex-m3
.thumb


/* Stack top address */
.word 0x20005000


/* Vector table */
.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object


g_pfnVectors:

    .word 0x20005000          /* Initial Stack Pointer */

    .word Reset_Handler       /* Reset Handler */

    .word NMI_Handler
    .word HardFault_Handler
    .word MemManage_Handler
    .word BusFault_Handler
    .word UsageFault_Handler

    .word 0
    .word 0
    .word 0
    .word 0

    .word SVC_Handler
    .word DebugMon_Handler
    .word 0
    .word PendSV_Handler
    .word SysTick_Handler



.size g_pfnVectors, .-g_pfnVectors



.text


.global Reset_Handler
.type Reset_Handler,%function


Reset_Handler:

    /* Call main function */

    bl main


stop:

    b stop



/* Default interrupt handlers */

NMI_Handler:

HardFault_Handler:

MemManage_Handler:

BusFault_Handler:

UsageFault_Handler:

SVC_Handler:

DebugMon_Handler:

PendSV_Handler:

SysTick_Handler:

    b .