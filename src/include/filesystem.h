#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 32
#define MAX_DIRS 10
#define MAX_DIRNAME_LENGTH 32

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    char content[256]; // Simple content storage
} File;

typedef struct Directory {
    char name[MAX_DIRNAME_LENGTH];
    File files[MAX_FILES];
    int file_count;
    struct Directory *subdirs[MAX_DIRS];
    int dir_count;
} Directory;

void init_file_system();
void mkdir(const char *dir_name);
void cd(const char *dir_name);
void ls();
void mkfile(const char *file_name);
void fluxedit(const char *file_name);
void sysinfo();

#endif // FILESYSTEM_H