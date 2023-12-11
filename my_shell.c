#include "shell.h"

/**
 * main - runs a command line interpreter
 *
 * Return: Always 0.
 */

/**1. Create a prompt
2. receive user input
3. tokenize the input so that i can get the arguments
4. create a child process
5. child process should execute the command, while parent waits
6. display results of the executed command */
int main(void)
{
	char *cmd = NULL;
	size_t n = 0;

	while(1)
	{
		prmpt();
		usr_cmd(cmd, n);
		exec_cmd(cmd);
	}
	free(cmd);
	return (0);
}
