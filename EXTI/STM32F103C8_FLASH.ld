/* STM32F103C8 Memory Layout */

/* Entry point */
ENTRY(Reset_Handler)


/* Memory definition */

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}


/* Sections */

SECTIONS
{

    /* Vector table and program code */

    .text :
    {
        KEEP(*(.isr_vector))

        *(.text)

        *(.text.*)

        . = ALIGN(4);

        _etext = .;

    } > FLASH



    /* Read-only data */

    .rodata :
    {
        *(.rodata)

        *(.rodata.*)

    } > FLASH



    /* Initialized variables */

    .data :
    {
        _sdata = .;

        *(.data)

        *(.data.*)

        _edata = .;

    } > RAM AT > FLASH



    /* Uninitialized variables */

    .bss :
    {

        _sbss = .;

        *(.bss)

        *(.bss.*)

        *(COMMON)

        _ebss = .;

    } > RAM



    /* Stack */

    . = ALIGN(4);

    _estack = ORIGIN(RAM) + LENGTH(RAM);

}