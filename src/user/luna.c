#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "luna.h"

// Function to change resolution
void change_resolution(int width, int height) {
    // Placeholder for resolution change logic
    printf("Changing resolution to %dx%d...\n", width, height);
}

// Function to display the status bar
void display_status_bar() {
    printf("\n==================== Luna GUI ====================\n");
    printf("You are now in the Luna GUI. Type 'exit' to close.\n");
    printf("===================================================\n");
}

void launch_luna() {
    display_status_bar(); // Show the status bar

    while (1) {
        char command[256];
        printf("luna> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting Luna...\n");
            break;
        } else if (strncmp(command, "setres ", 7) == 0) {
            int width, height;
            if (sscanf(command + 7, "%d %d", &width, &height) == 2) {
                change_resolution(width, height);
            } else {
                printf("Usage: setres <width> <height>\n");
            }
        } else {
            execute_command(command);
        }
    }
}