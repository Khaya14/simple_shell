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
#define _BUF_SIZE 1080

extern char **environ;

struct bltn_cmd
{
	char *file;
	int (*func)(char **arr_tkns);
};

/* Process functions */
void prmpt(void);
ssize_t usrcmd(char **i, size_t *byt_all, int status);
int _kind(char *cmd, char **arr_tkns);
void cigint_(int cig);

/* arrays & tokens */
size_t nm_tkn(char *usr_inpt, char *dlm);
char **arr_tkn(char *usr_inpt, char *dlm);
char *_gt_envv(const char *file);
char *_wh(char *fname);

/* memory management */
char *ch_mllc(char **_buf, size_t mllc_sz, char *msg);
char **arr_mllc(char **arr, size_t mllc_sz, char *msg);
void _wh_free(char **var_p, char **arr_tkns);
void mem_free(char **arr_tkns, char *inp);

/* builtin commands & environ */
int env_bltn(__attribute((unused)) char **arr_tkn);
int bltn_exec(char **arr_tkns);
int bltn_check(char **arr_tkns);
int bltn_exit(char **arr_tkns);

#endif
