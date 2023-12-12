#include <stdio.h>
#include <stdlib.h>

/**
 * main - implements a code that displays current environment.
 *
 * @cur: current envirnment
 *
 * Return: 0
 */

extern char **environ;

int main(void)
{
	        for (char **cur = environ; *cur != NULL; cur++)
			        {
					                printf("%s\n", *cur);
							        }

		        return (0);
}
