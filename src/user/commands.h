#ifndef COMMANDS_H
#define COMMANDS_H

void execute_command(const char *command);
void mkdir_command(const char *dir_name);
void cd_command(const char *dir_name);
void ls_command();
void mkfile_command(const char *file_name);
void fluxedit_command(const char *file_name);
void sysinfo_command();

#endif // COMMANDS_H