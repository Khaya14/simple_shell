#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void prmpt(void);
void usr_cmd(char *cmd, size_t n_ch, char **args);
void exec_cmd(char **args);

#endif
