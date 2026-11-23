
# Embedded QEMU Blink

Proyecto bare-metal para ARM Cortex-M3 ejecutado en QEMU.

## Descripción

Firmware en C sin HAL ni biblioteca estándar. Simula un microcontrolador
Cortex-M3 en la placa MPS2-AN385 de QEMU.

## Herramientas

- arm-none-eabi-gcc
- QEMU qemu-system-arm
- GDB gdb-multiarch
- Make

## Cómo compilar y ejecutar

```bash
make       # Compila el proyecto.
make run   # Ejecuta el firmware en QEMU.
make debug # Abre el puerto GDB en 3333.
```

El proyecto fue desarrollado en Linux Debian desde una terminal sin
entorno gráfico, utilizando tmux.
