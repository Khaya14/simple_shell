#include "shell.h"

/**
 * ln_tkn - length of token
 * @s: string
 * @dlm: delimiter
 *
 * Return: integer
 */
int ln_tkn(char *s, char *dlm)
{
	int _i = 0, ln = 0;

	while (*(s + _i) && *(s + _i) != *dlm)
	{
		ln++;
		_i++;
	}

	return (ln);
}
/**
 * tkn_cnt - counts tokens
 * @s: arg 1
 * @dlm: arg 2
 *
 * Return: integer
 */
int tkn_cnt(char *s, char *dlm)
{
	int _i, tkns = 0, ln = 0;

	for (_i = 0; *(s + _i); _i++)
		ln++;

	for (_i = 0; _i < ln; _i++)
	{
		if (*(s + _i) != *dlm)
		{
			tkns++;
			_i += ln_tkn(s + _i, dlm);
		}
	}

	return (tkns);
}

/**
 * strtok_ - functyion to tokenize.
 * @ln: The string.
 * @dlm: the delimeter
 *
 * Return: A pointer to an array of tokens.
 */
char **strtok_(char *ln, char *dlm)
{
	char **p;
	int _i = 0, tkns, k, alpha, lll;

	tkns = tkn_cnt(ln, dlm);
	if (tkns == 0)
		return (NULL);

	p = malloc(sizeof(char *) * (tkns + 2));
	if (!p)
		return (NULL);

	for (k = 0; k < tkns; k++)
	{
		while (ln[_i] == *dlm)
			_i++;

		alpha = ln_tkn(ln + _i, dlm);

		p[k] = malloc(sizeof(char) * (alpha + 1));
		if (!p[k])
		{
			for (_i -= 1; _i >= 0; _i--)
				free(p[_i]);
			free(p);
			return (NULL);
		}

		for (lll = 0; lll < alpha; lll++)
		{
			p[k][lll] = ln[_i];
			_i++;
		}

		p[k][lll] = '\0';
	}
	p[k] = NULL;
	p[k + 1] = NULL;

	return (p);
}
