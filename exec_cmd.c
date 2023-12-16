#include "shell.h"

/**
 * exec_cmd - executes a particular command in achild process
 * @arr_args: argument array
 * @top: pointer to the top of the argument array
 *
 * Return: error message on failm exit status on success
 */
int exec_cmd(char **arr_args, char **top)
{
	pid_t kind;
	int status, f = 0, result = 0;
	char *cmd = arr_args[0];

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		f = 1;
		cmd = locate_cmd(cmd);
	}

	if (!cmd || (access(cmd, F_OK) == -1))
	{
		if (errno == EACCES)
			result = (error_creator(arr_args, 126));
		else
			result = (error_creator(arr_args, 127));
	}
	else
	{
		kind = fork();
		if (kind == -1)
		{
			if (f)
				free(cmd);
			perror("Error child process:");
			return (1);
		}
		if (kind == 0)
		{
			execve(cmd, arr_args, environ);
			if (errno == EACCES)
				result = (error_creator(arr_args, 126));
			env_free();
			args_free(arr_args, top);
			_exit(result);
		}
		else
		{
			wait(&status);
			result = WEXITSTATUS(status);
		}
	}
	if (f)
		free(cmd);
	return (result);
}

/**
 * handles_sig - upon a signal, prints a new prompt
 * @_signal: the signal detected
 */
void handles_sig(int _signal)
{
	char *prompt_new = "\n$ ";

	(void)_signal;
	signal(SIGINT, handles_sig);
	write(STDIN_FILENO, prompt_new, 3);
}
