#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "basic.h"

#define MAX_LINE_LENGTH 100
#define MAX_VAR_LENGTH  20
#define MAX_VARS        100

typedef struct {
    char name[MAX_VAR_LENGTH];
    int value;
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;

void set_variable(const char *name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    strcpy(variables[var_count].name, name);
    variables[var_count].value = value;
    var_count++;
}

int get_variable(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return 0;
}

void print_command(const char *args) {
    printf("%s\n", args);
}

void let_command(const char *args) {
    char var[MAX_VAR_LENGTH];
    int value;
    sscanf(args, "%s = %d", var, &value);
    set_variable(var, value);
}

void run_basic_interpreter() {
    char line[MAX_LINE_LENGTH];
    while (1) {
        printf("BASIC> ");
        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }
        line[strcspn(line, "\n")] = 0; // Remove newline

        if (strncmp(line, "PRINT ", 6) == 0) {
            print_command(line + 6);
        } else if (strncmp(line, "LET ", 4) == 0) {
            let_command(line + 4);
        } else if (strcmp(line, "EXIT") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", line);
        }
    }
}

int main() {
    run_basic_interpreter();
    return 0;
}