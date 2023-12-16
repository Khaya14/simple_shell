#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#define _EOF -2
#define _EXIT -3

extern char **environ;

typedef struct list_d
{
	char *dir_name;
	struct list_d *next;
} list_d;

typedef struct bltn_t
{
	char *file;
	int (*d)(char **argv, char **top);
} bltn_t;

char *cmd;
int cmd_log;

void handles_sig(int _signal);
int exec_cmd(char **arr_args, char **top);
char *locate_cmd(char *cmd);
list_d *path_direct(char *_path);
char *_full_pathname(char *_path);
void free_ls(list_d *head);
list_d *end_node(list_d **head, char *directory);
char *env_error(char **arr_args);
char *al_error(char **arr_args);
char *exit_error(char **arr_args);
char *cd_error(char **arr_args);
char *syntax_error(char **arr_args);
char *err_permission(char **arr_args);
char *cmd_error(char **arr_args);
int ln_num(int n);
char *_i_toa(int n);
int error_creator(char **arr_args, int err_n);
void env_free(void);
char **cp_env(void);
char **_gets_env(const char *s);
int exec_file(char *f_path, int *result);
int open_fail(char *f_path);
void args_free(char **arr_args, char **top);
char *_getspid(void);
char *getsenv_val(char *start, int ln);
void replace_var(char **ln, int *result);
void logic(char *ln, ssize_t *nw_len);
ssize_t getsnew_len_(char *ln);
void ln_handlr(char **ln, ssize_t rd);
ssize_t _get_line(char **lnptr, size_t *sz, FILE *input_stream);
void *r_alloc(void *mem_ptr, unsigned int prev_sz, unsigned int nxt_sz);
void create_lnptr(char **lnptr, size_t *sz, size_t szb, char *_buf);
char *args_get(char *ln, int *result);
int args_call(char **arr_args, char **top, int *result);
int args_run(char **arr_args, char **top, int *result);
int args_handlr(int *result);
int (*bltn_gets(char *cmd))(char **arr_args, char **top);
int exit_function(char **arr_args, char **top);
int env_function(char **arr_args, char __attribute__((__unused__)) **top);
void create_lnptr(char **lnptr, size_t *sz, size_t szb, char *_buf);
void *r_alloc(void *mem_ptr, unsigned int prev_sz, unsigned int nxt_sz);
ssize_t _get_line(char **lnptr, size_t *sz, FILE *input_stream);
int args_check(char **arr_args);
int ln_tkn(char *s, char *dlm);
int tkn_cnt(char *s, char *dlm);
char **strtok_(char *ln, char *dlm);
#endif
