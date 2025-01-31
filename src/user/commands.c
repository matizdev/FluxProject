#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include "filesystem.h"

void execute_command(const char *command) {
    if (strncmp(command, "mkdir ", 6) == 0) {
        mkdir_command(command + 6);
    } else if (strncmp(command, "cd ", 3) == 0) {
        cd_command(command + 3);
    } else if (strcmp(command, "ls") == 0) {
        ls_command();
    } else if (strncmp(command, "mkfile ", 7) == 0) {
        mkfile_command(command + 7);
    } else if (strncmp(command, "fluxedit ", 9) == 0) {
        fluxedit_command(command + 9);
    } else if (strcmp(command, "sysinfo") == 0) {
        sysinfo_command();
    } else {
        printf("Command not found: %s\n", command);
    }
}

void mkdir_command(const char *dir_name) {
    if (strlen(dir_name) == 0) {
        printf("Error: Directory name cannot be empty.\n");
        return;
    }
    mkdir(dir_name);
}

void cd_command(const char *dir_name) {
    if (strlen(dir_name) == 0) {
        printf("Error: Directory name cannot be empty.\n");
        return;
    }
    cd(dir_name);
}

void ls_command() {
    ls();
}

void mkfile_command(const char *file_name) {
    if (strlen(file_name) == 0) {
        printf("Error: File name cannot be empty.\n");
        return;
    }
    mkfile(file_name);
}

void fluxedit_command(const char *file_name) {
    if (strlen(file_name) == 0) {
        printf("Error: File name cannot be empty.\n");
        return;
    }
    fluxedit(file_name);
}

void sysinfo_command() {
    sysinfo();
}