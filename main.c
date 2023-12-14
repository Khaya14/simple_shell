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
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	char *usr_inpt;
	size_t nm_ch;
	int status;


	usr_inpt = NULL;
	nm_ch = 0;

	while (1)
	{
		prmpt();
		usercmd(&usr_inpt, &nm_ch, status);
	}

	return (0);
}
