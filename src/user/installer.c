#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void list_disks() {
    // This is a placeholder. In a real implementation, you would query the system for available disks.
    printf("Available disks:\n");
    printf("1. /dev/sda\n");
    printf("2. /dev/sdb\n");
    printf("3. /dev/sdc\n");
}

void format_disk(const char *disk) {
    // Placeholder for disk formatting logic
    printf("Formatting disk %s...\n", disk);
    // Actual formatting code would go here
}

void install_kernel(const char *disk) {
    // Placeholder for kernel installation logic
    printf("Installing kernel to %s...\n", disk);
    // Actual installation code would go here
}

int main() {
    char command[256];
    char disk[256];

    printf("Welcome to the Flux Installer!\n");
    printf("Type 'install' to begin installation.\n");

    while (1) {
        printf("flux-installer> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "install") == 0) {
            list_disks();
            printf("Select a disk to install (e.g., /dev/sda): ");
            fgets(disk, sizeof(disk), stdin);
            disk[strcspn(disk, "\n")] = 0; // Remove newline

            format_disk(disk);
            install_kernel(disk);
            printf("Installation complete!\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}