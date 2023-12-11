#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void prmpt();
ssize_t usr_cmd(char *cmd, size_t n);
void exec_cmd(char *cmd);

#endif
