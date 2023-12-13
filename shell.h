#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void prmpt(void);
void usr_cmd(int argc, char *argv[]);
int exec_cmd(char *cmd);
int _strlen(char *str);

#endif
