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

<<<<<<< HEAD
=======
void init_sh(void);
void prmpt(void);
void usr_cmd(int argc, char *argv[]);
int exec_cmd(char *cmd);
int _strlen(char *str);
void init_sh(void);

>>>>>>> 1d966f2d288e2aef4a06f4f07a5646c840b6c71e
#endif
