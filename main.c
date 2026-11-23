#define UART0_BASE 0x40004000
#define UART0_DATA (*(volatile unsigned int *)(UART0_BASE + 0x00))
#define UART0_STATE (*(volatile unsigned int *)(UART0_BASE + 0x04))
#define UART0_CTRL (*(volatile unsigned int *)(UART0_BASE + 0x08))
#define UART_TX_FULL (1U << 0)

static void UartPutc(char character) {
  while (UART0_STATE & UART_TX_FULL)
    ;
  UART0_DATA = (unsigned int)character;
}

static void UartPuts(const char *text) {
  while (*text != '\0') {
    UartPutc(*text++);
  }
}

static void Delay(volatile unsigned int cycles) {
  while (cycles-- > 0)
    ;
}

int main(void) {
  UART0_CTRL = 1; // Activa el UART.
  UartPuts("Hola desde Cortex-M3\n");

  while (1) {
    UartPuts("tick\r\n");
    Delay(500000U);
  }
}
