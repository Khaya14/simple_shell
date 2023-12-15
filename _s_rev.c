#include "shell.h"

/**
 * _s_rev - this function returns a string in reverse
 * @_s: string to be reversed
 *
 * Return: void
 */
void _s_rev(char *_s)
{
	int id, ln;
	char  buf;

	ln = 0;
	while (_s[ln] != '\0')
		ln++;
	ln--;
	for (id = 0; id++ < ln; id++, ln--)
	{
		buf = _s[id];
		_s[id] = _s[ln];
		_s[ln] = buf;
	}
}
