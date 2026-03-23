MEMORY {
FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
    .text : {
        *(.isr_vector)
        *(.text*)
    } > FLASH

    .bss : {
        *(.bss*)
    } > RAM

    .data : {
        *(.data*)
    } > RAM AT > FLASH
}
