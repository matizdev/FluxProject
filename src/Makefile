# Makefile for Flux Microkernel

# Compiler and assembler
CC = gcc
ASM = nasm

# Compiler and linker flags
CFLAGS = -ffreestanding -I/usr/include/SDL2 -I./src/include -D_REENTRANT
LDFLAGS = -lSDL2

# Source files
BOOTLOADER_SRC = bootloader/fbl.asm
KERNEL_SRC = kernel/kernel.c
USER_SRC = user/init.c user/installer.c user/commands.c user/filesystem.c user/luna.c
BASIC_SRC = src/basic.c # Add your Basic Language source file here

# Output files
BOOTLOADER_BIN = bootloader.bin
KERNEL_BIN = kernel.bin
USER_BIN = user.bin
BASIC_BIN = basic.bin # Output binary for Basic Language
OS_IMAGE = os_image.bin

# Targets
all: $(BOOTLOADER_BIN) $(KERNEL_BIN) $(USER_BIN) $(BASIC_BIN) $(OS_IMAGE)

# Bootloader
$(BOOTLOADER_BIN): $(BOOTLOADER_SRC)
    $(ASM) -f bin $(BOOTLOADER_SRC) -o $(BOOTLOADER_BIN)

# Kernel
$(KERNEL_BIN): $(KERNEL_SRC)
    $(CC) $(CFLAGS) -c $(KERNEL_SRC) -o kernel.o
    ld -Ttext 0x1000 --oformat binary -o $(KERNEL_BIN) kernel.o

# User space applications
$(USER_BIN): $(USER_SRC)
    $(CC) $(CFLAGS) -c $(USER_SRC) -o user.o
    ld -Ttext 0x2000 --oformat binary -o $(USER_BIN) user.o

# Basic Language
$(BASIC_BIN): $(BASIC_SRC)
    $(CC) $(CFLAGS) -c $(BASIC_SRC) -o basic.o
    ld -Ttext 0x3000 --oformat binary -o $(BASIC_BIN) basic.o

# Create OS image
$(OS_IMAGE): $(BOOTLOADER_BIN) $(KERNEL_BIN) $(USER_BIN) $(BASIC_BIN)
    cat $(BOOTLOADER_BIN) $(KERNEL_BIN) $(USER_BIN) $(BASIC_BIN) > $(OS_IMAGE)

# Run the OS in QEMU
run: $(OS_IMAGE)
    qemu-system-x86_64 -drive format=raw,file=$(OS_IMAGE)

# Clean up generated files
clean:
    rm -f *.o *.bin $(OS_IMAGE) kernel.o user.o basic.o