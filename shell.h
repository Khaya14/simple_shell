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
ssize_t usrcmd(char **i, size_t *byt_all, int status);

/* arrays & tokens */
size_t nm_tkn(char *usr_inpt, char * dlm);
char **arr_tkn(char *usr_inpt, char *dlm);

/* memory management */
char *ch_mllc(char **_buf, size_t mllc_sz, char msg);



#endif
