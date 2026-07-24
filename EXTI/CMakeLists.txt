
cmake_minimum_required(VERSION 3.20)


set(MCU cortex-m3)
set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_SYSTEM_PROCESSOR arm)


set(CMAKE_C_COMPILER arm-none-eabi-gcc)

set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_TRY_COMPILE_TARGET_TYPE
STATIC_LIBRARY)

project(STM32_BareMetal C ASM)
include_directories(

 ${CMAKE_SOURCE_DIR}/inc
 ${CMAKE_SOURCE_DIR}/FreeRTOS/include
 ${CMAKE_SOURCE_DIR}/FreeRTOS/portable/GCC/ARM_CM3
)

# Compiler flags

add_compile_options(

    -mcpu=${MCU}
    -mthumb

    -Wall
    -Wextra

    -O0

    -ffreestanding
    -fdata-sections
    -ffunction-sections

)



# Linker flags

add_link_options(

    -mcpu=${MCU}
    -mthumb

    -T${CMAKE_SOURCE_DIR}/STM32F103C8_FLASH.ld

    -nostartfiles

    -Wl,--gc-sections

)



# Source files

add_executable(

    firmware.elf

    src/main.c
    src/system.c
    src/clock.h
    src/gpio.h
    startup_stm32f103c8.s

    FreeRTOS/tasks.c
    FreeRTOS/queue.c
    FreeRTOS/list.c
    FreeRTOS/timers.c
    FreeRTOS/event_groups.c
    FreeRTOS/stream_buffer.c
    FreeRTOS/portable/GCC/ARM_CM3/port.c
    FreeRTOS/portable/GCC/MemMang/heap_4.c
     

)

target_compile_options(firmware.elf PRIVATE
    -g
    -O0
)

# Generate binary file

add_custom_command(

    TARGET firmware.elf POST_BUILD

    COMMAND arm-none-eabi-objcopy

    -O binary

    firmware.elf

    firmware.bin

)