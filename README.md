
# embedded-qemu-blink

Proyecto bare-metal para ARM Cortex-M3 corriendo en QEMU

## Descripcion
Firmware en C sin HAL ni biblioteca estandar.
Simula un microcontrolador STM3 en QEMU mps-an385

## Herramientas
- arm-none-eabi-gcc
- QEMU qemu-system-arm
- GBD gdb-multiarch
- Make

## Como compilar y correr el proyecto
```bash
make # compila el proyecto
make run # ejecuta QEMU
make debug # abre puerto GDB en :3333
```
Realice el proyecto en un entorno controlado en Linux Debian especificamente, desde una terminal sin ningun tipo de entorno grafico, unicamente utiliando la herramienta tmux.
