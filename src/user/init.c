#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "luna.h"

int main() {
    printf("Welcome to Flux Microkernel!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        char command[256];
        printf("flux> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  mkdir <directory_name> - Create a new directory\n");
            printf("  cd <directory_name> - Change the current directory\n");
            printf("  ls - List files and directories\n");
            printf("  mkfile <file_name> - Create a new file\n");
            printf("  fluxedit <file_name> - Edit the content of a file\n");
            printf("  sysinfo - Display system information\n");
            printf("  startluna - Launch the Luna GUI\n");
            printf("  exit - Exit the shell\n");
        } else if (strcmp(command, "startluna") == 0) {
            launch_luna(); // Launch the GUI
        } else {
            execute_command(command);
        }
    }

    return 0;
}