#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "commands.h"
#include "filesystem.h"

#define MAX_PROCESSES 256

typedef struct {
    int pid;
    char name[32];
} process_t;

process_t process_table[MAX_PROCESSES];

void kernel_main() {
    if (!init_memory()) {
        printf("Memory initialization failed!\n");
        return;
    }
    
    if (!init_processes()) {
        printf("Process initialization failed!\n");
        return;
    }
    
    if (!init_file_system()) {
        printf("File system initialization failed!\n");
        return;
    }

    // Start the main shell
    start_user_process("init");
}

int init_memory() {
    // Initialize memory management structures
    // Return 1 on success, 0 on failure
    return 1;
}

int init_processes() {
    memset(process_table, 0, sizeof(process_table));
    // Return 1 on success, 0 on failure
    return 1;
}

void start_user_process(const char *process_name) {
    if (strcmp(process_name, "init") == 0) {
        init_process();
    } else if (strcmp(process_name, "installer") == 0) {
        installer_process();
    }
}

void init_process() {
    printf("Welcome to Flux Microkernel!\n");
    while (1) {
        char command[256];
        printf("flux> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline
        execute_command(command);
    }
}

void installer_process() {
    printf("Starting installer process...\n");
    // Basic implementation for the installer process
    // Add actual installation logic here
    while (1) {
        // Installer logic loop
    }
}