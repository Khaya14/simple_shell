#include "shell.h"

/**
 * main - runs a command line interpreter on UNIX
 * The function displays a prompt and then takes a users command
 * The command line always ends on a new line
 * It can handle command lines with arguments
 * Handles the path
 * it also is able to handle certain builtin functions
 * @argc: counts the number of arguments
 * @argv: pointer to an array of arguments stored
 * @envp: pointer to the environ variable
 *
 * Return: Always 0.
 */
int main(__attribute((unused)) int argc,
		__attribute((unused)) char **argv,
		__attribute((unused)) char **envp)
{
	char *usr_inp, *dlm, *wh_path;
	size_t nm_ch, b_allc;
	int status = 0;
	char **arr_tkns;

	signal(SIGINT, cigint_);
	dlm = " \n\t\r_";
	usr_inp = NULL;
	nm_ch = b_allc = 0;
	while (1)
	{
		b_allc++;
		prmpt();
		usrcmd(&usr_inp, &nm_ch, status);
		arr_tkns = arr_tkn(usr_inp, dlm);
		if (arr_tkns == NULL)
			status = 0;
		else
		{
			if (bltn_check(arr_tkns))
			{
				if (bltn_exec(arr_tkns) == _BUF_SIZE)
				{
					mem_free(arr_tkns, usr_inp);
					exit(status);
				}
			}
			else
			{
				wh_path = _wh(arr_tkns[0]);
				if (wh_path != NULL)
					status = _kind(wh_path, arr_tkns);
				else
					status = err_msg(argv, arr_tkns, b_allc);
			}
		}
		mem_free(arr_tkns, usr_inp);
		usr_inp = NULL;
	}
	return (0);
}
