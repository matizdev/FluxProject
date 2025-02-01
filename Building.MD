# Building Flux

## Project Structure

- `bootloader/`: Contains the bootloader code.
- `kernel/`: Contains the kernel and file system code.
- `user/`: Contains user-space utilities.
- `include/`: Contains Headers for C Files
- `Makefile`: Build instructions for the project.

## Building the Project

1. Ensure you have NASM and GCC installed.
2. Run `make` to build the bootloader and kernel.
3. Run `make run` to run the kernel in QEMU.
4. To clean up generated files, run `make clean`

    ### Manual Building (Outdated! DO NOT USE THIS METHOD)

    1. Create a Bootable Image: `nasm -f bin bootloader/fbl.asm -o bootloader.bin`
    2. Compile the kernel: `gcc -ffreestanding -c kernel/kernel.c -o kernel.o`
    3. Link the kernel: `ld -Ttext 0x1000 --oformat binary -o kernel.bin kernel.o`
    4. Compile user space applications:
        ```bash
        gcc -ffreestanding -c user/init.c -o init.o
        gcc -ffreestanding -c user/installer.c -o installer.o
        gcc -ffreestanding -c user/commands.c -o commands.o
        gcc -ffreestanding -c user/filesystem.c -o filesystem.o
        gcc -ffreestanding -c user/luna.c -o luna.o
        ld -Ttext 0x2000 --oformat binary -o user.bin init.o installer.o commands.o filesystem.o luna.o
        ```
    5. Create a bootable image: `cat bootloader.bin kernel.bin user.bin > os_image.bin`
    6. Run the OS in QEMU: `qemu-system-x86_64 -drive format=raw,file=os_image.bin`
    

## Running the Bootloader

```bash
qemu-system-x86_64 -drive format=raw,file=fbl.img
