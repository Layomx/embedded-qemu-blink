#define UARTO_BASE 0x40004000
#define UARTO_DATA (*(volatile unsigned int *)(UARTO_BASE + 0x00))
#define UARTO_STATE (*(volatile unsigned int *)(UARTO_BASE + 0x04)) 
#define UARTO_CTRL (*(volatile unsigned int *)(UARTO_BASE + 0x08))
#define UART_TX_FULL (1 << 0)

void uart_putc(char c) {
    while (UARTO_STATE & UART_TX_FULL);
    UARTO_DATA = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

int main(void) {
    UARTO_CTRL = 1; // Enable UART
    uart_puts("Hola desde Cortex-M3\n");

    volatile int i = 0;
    while (1) {
        uart_puts("tick\r\n");
        for (i = 0; i < 500000; i++);
    }
    return 0;
}
