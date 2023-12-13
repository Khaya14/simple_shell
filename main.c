#include "shell.h"

/**
 * main - initiates a shell
 * @argc: number of arguments passed to commandline
 * @argv: array of argument strings
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	usr_cmd(argc, argv);
	return (0);
}
