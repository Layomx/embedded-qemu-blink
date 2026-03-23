extern int main(void);
extern unsigned long _estack;

void Reset_Handler(void) {
    main();
    while(1);
}

__attribute__((section(".isr_vector")))
void (*vectors[])(void) = {
    (void*)&_estack, // Initial Stack Pointer
    Reset_Handler,   // Reset Handler
};
