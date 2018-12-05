#include <stddef.h>
#include <stdint.h>
#include <kernel/atag.h>
#include <kernel/interrupts.h>
#include <kernel/timer.h>
#include <kernel/mem.h>
#include <kernel/stdio.h>
static interrupt_registers_t * interrupt_regs;

static interrupt_handler_f handlers[72];
static interrupt_clearer_f clearers[72];

extern void move_exception_vector(void);
static inline void mmio_write(uint32_t reg, uint32_t data);
static inline uint32_t mmio_read(uint32_t reg);
static inline void delay(int32_t count);
void uart_init();
void uart_putc(unsigned char c);
unsigned char uart_getc();
void uart_puts(const char* str);
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags);
void print_menu();

