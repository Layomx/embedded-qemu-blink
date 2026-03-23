CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -nostdlib -nostartfiles -Wall -g
TARGET = firmware

all: $(TARGET).elf

$(TARGET).elf: main.c startup.c
	$(CC) $(CFLAGS) -T linker.ld $^ -o $@

clean:
	rm -f *.elf

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
