#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filesystem.h"

Directory root;
Directory *current_dir;

void init_file_system() {
    strcpy(root.name, "root");
    root.file_count = 0;
    root.dir_count = 0;
    current_dir = &root; // Start in the root directory
}

void mkdir(const char *dir_name) {
    if (current_dir->dir_count >= MAX_DIRS) {
        printf("Maximum directory limit reached.\n");
        return;
    }
    Directory *new_dir = malloc(sizeof(Directory));
    strcpy(new_dir->name, dir_name);
    new_dir->file_count = 0;
    new_dir->dir_count = 0;
    current_dir->subdirs[current_dir->dir_count++] = new_dir;
    printf("Directory '%s' created.\n", dir_name);
}

void cd(const char *dir_name) {
    for (int i = 0; i < current_dir->dir_count; i++) {
        if (strcmp(current_dir->subdirs[i]->name, dir_name) == 0) {
            current_dir = current_dir->subdirs[i];
            printf("Changed directory to '%s'.\n", dir_name);
            return;
        }
    }
    printf("Directory '%s' not found.\n", dir_name);
}

void ls() {
    printf("Files in '%s':\n", current_dir->name);
    for (int i = 0; i < current_dir->file_count; i++) {
        printf("  %s\n", current_dir->files[i].name);
    }
    for (int i = 0; i < current_dir->dir_count; i++) {
        printf("  %s/\n", current_dir->subdirs[i]->name);
    }
}

void mkfile(const char *file_name) {
    if (current_dir->file_count >= MAX_FILES) {
        printf("Maximum file limit reached.\n");
        return;
    }
    File *new_file = &current_dir->files[current_dir->file_count++];
    strcpy(new_file->name, file_name);
    strcpy(new_file->content, ""); // Initialize with empty content
    printf("File '%s' created.\n", file_name);
}

void fluxedit(const char *file_name) {
    // Check if the file exists
    for (int i = 0; i < current_dir->file_count; i++) {
        if (strcmp(current_dir->files[i].name, file_name) == 0) {
            printf("Editing file '%s'. Current content:\n%s\n", file_name, current_dir->files[i].content);
            printf("Enter new content (type 'END' on a new line to save):\n");

            char line[256];
            char new_content[1024] = ""; // Buffer for new content
            while (1) {
                fgets(line, sizeof(line), stdin);
                if (strcmp(line, "END\n") == 0) {
                    break; // Exit editing mode
                }
                strcat(new_content, line); // Append new line to content
            }
            strcpy(current_dir->files[i].content, new_content); // Save new content
            printf("File '%s' updated.\n", file_name);
            return;
        }
    }
    printf("File '%s' not found.\n", file_name);
}

void sysinfo() {
    printf("System Information:\n");
    printf("Kernel Version: Flux 0.1\n");
    printf("Available Memory: 512MB\n");
    printf("Current Directory: %s\n", current_dir->name);
}