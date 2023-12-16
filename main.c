#include "shell.h"

/**
 * main - this function runs a UNIX command line interpreter
 * @argc: counts the number of arguments
 * @argv: A pointer to an array of arguments
 *
 * Return: value of the last command that was executed
 */
int main(int argc, char *argv[])
{
	int result = 0, result_n;
	int *exec_result = &result_n;
	char *my_prmpt = "$ ", *nl = "\n";

	cmd = argv[0];
	cmd_log = 1;
	signal(SIGINT, handles_sig);

	*exec_result = 0;
	environ = cp_env();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		result = exec_file(argv[1], exec_result);
		env_free();
		return (*exec_result);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (result != _EOF && result != _EXIT)
			result = args_handlr(exec_result);
		env_free();
		return (*exec_result);
	}

	while (1)
	{
		write(STDOUT_FILENO, my_prmpt, 2);
		result = args_handlr(exec_result);
		if (result == _EOF || result == _EXIT)
		{
			if (result == _EOF)
				write(STDOUT_FILENO, nl, 1);
			env_free();
			exit(*exec_result);
		}
	}

	env_free();
	return (*exec_result);
}
