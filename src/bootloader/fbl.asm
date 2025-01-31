; fbl.asm - Bootloader for Flux

[org 0x7C00]          ; BIOS loads the bootloader at this address

section .text
    ; Set up the stack
    xor ax, ax        ; Clear AX
    mov ds, ax        ; Set DS to 0
    mov es, ax        ; Set ES to 0
    mov ss, ax        ; Set SS to 0
    mov sp, 0x7C00    ; Set stack pointer

    ; Display the boot menu
    mov si, menu_message ; Load the address of the menu message
    call print_string    ; Call the print function

    ; Wait for a key press
    call wait_for_key

    ; Check which key was pressed
    cmp al, 'I'         ; Compare with 'I' for install
    je load_installer    ; Jump to installer if 'I' is pressed
    cmp al, 'K'         ; Compare with 'K' for kernel
    je load_kernel       ; Jump to kernel if 'K' is pressed

    ; If neither key is pressed, loop back
    jmp $

load_installer:
    ; Load the installer (assuming it's at 0x2000)
    mov ax, 0x2000      ; Load installer address
    mov ds, ax          ; Set DS to point to the installer
    jmp 0x2000          ; Jump to the installer

load_kernel:
    ; Load the kernel (assuming it's at 0x1000)
    mov ax, 0x1000      ; Load kernel address
    mov ds, ax          ; Set DS to point to the kernel
    jmp 0x1000          ; Jump to the kernel

print_string:
    ; Print the string pointed to by SI
    mov ah, 0x0E       ; BIOS teletype function
.next_char:
    lodsb              ; Load byte at DS:SI into AL and increment SI
    cmp al, 0          ; Check for null terminator
    je .done           ; If null, we're done
    int 0x10          ; Call BIOS to print character
    jmp .next_char     ; Repeat for next character
.done:
    ret

wait_for_key:
    ; Wait for a key press
    mov ah, 0x00       ; BIOS function to read a key
    int 0x16           ; Call BIOS
    ret

section .data
menu_message db 'Press I to install or K to boot the kernel:', 0
; Fill the rest of the boot sector with zeros
times 510 - ($ - $$) db 0
dw 0xAA55             ; Boot signature