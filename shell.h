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
void cigint_(int cig);

/* istrings, arrays & tokens */
size_t nm_tkn(char *usr_inpt, char *dlm);
char **arr_tkn(char *usr_inpt, char *dlm);
char *_gt_envv(const char *file);
char *_wh(char *fname);
void _s_rev(char *_s);
char *_i_t_oa(size_t cmd_nm);
int d_count(size_t cmd_nm);

/* memory management */
char *ch_mllc(char **_buf, size_t mllc_sz, char *msg);
char **arr_mllc(char **arr, size_t mllc_sz, char *msg);
void _wh_free(char **var_p, char **arr_tkns);
void mem_free(char **arr_tkns, char *inp);
void *r_alloc(void *mem_ptr, unsigned int prev_sz, unsigned int nxt_sz);
void create_lnptr(char **lnptr, size_t *sz, size_t szb, char *_buf);
ssize_t _get_line(char **lnptr, size_t *sz, FILE *input_stream);

/* builtin commands & environ */
int env_bltn(__attribute((unused)) char **arr_tkn);
int bltn_exec(char **arr_tkns);
int bltn_exit(char **arr_tkns);
int bltn_check(char **arr_tkns);

/* resource codes */
int err_msg(char **arr, char **arr_tkns, size_t b_allc);

#endif
