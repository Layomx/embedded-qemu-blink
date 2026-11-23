#include <stdint.h>

extern void Reset_Handler(void);
extern int main(void);
extern unsigned long _estack;
extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

static void InitializeData(void) {
  unsigned long *source = &_sidata;
  unsigned long *destination = &_sdata;

  while (destination < &_edata) {
    *destination++ = *source++;
  }

  destination = &_sbss;
  while (destination < &_ebss) {
    *destination++ = 0;
  }
}

void Reset_Handler(void) {
  InitializeData();
  main();
  while (1)
    ;
}

__attribute__((section(".isr_vector"))) const uint32_t Vectors[] = {
    (uint32_t)&_estack, // Puntero inicial de pila.
    (uint32_t)Reset_Handler, // Rutina de arranque.
};
