CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -ffreestanding -fno-builtin \
	-fno-stack-protector -nostdlib -nostartfiles -Wall -Wextra -Wpedantic -g
TARGET = firmware
MAP = $(TARGET).map

all: $(TARGET).elf

$(TARGET).elf: main.c startup.c
	$(CC) $(CFLAGS) -Wl,-Map=$(MAP) -T linker.ld $^ -o $@

clean:
	rm -f *.elf *.map

run: $(TARGET).elf
	qemu-system-arm \
		-machine mps2-an385 \
		-cpu cortex-m3 \
		-nographic \
		-kernel $(TARGET).elf

debug: $(TARGET).elf
	qemu-system-arm \
		-machine mps2-an385 \
		-cpu cortex-m3 \
		-nographic \
		-kernel $(TARGET).elf \
		-S -gdb tcp::3333

.PHONY: all clean run debug
