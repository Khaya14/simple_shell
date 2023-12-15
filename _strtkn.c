#include "shell.h"

/**
 * strtkn - function that tokenizes a string.
 *
 * @ln: string
 * @dlm: delimeter character to tokenize string by.
 *
 * Return: pointer to array containing tokenised words.
 */

char **strtkn(char *ln, char *dlm)
{
	char **pntr;
	int ix = 0, tkns, ts, ltrs, ls;

	tkns = count_tkns(line, dlm);
	if (tkns == 0)
		return (NULL);

	pntr = malloc(sizeof(char *) * (tkns + 2));
	if (!pntr)
		return (NULL);

	for (ts = 0; t < tkns; ts++)
	{
		while (ln[ix] == dlm)
			ix++;

		ltrs = tkn_len(ln + ix, dlm);

		pntr[t] = malloc(sizeof(char) * (ltrs + 1));
		if (!pntr[t])
		{
			for (ix -= 1; ix >= 0; ix--)
				free(pntr[ix]);
			free(pntr);
			return (NULL);
		}

		for (ls = 0; ls < ltrs; ls++
		{
				pntr[ts][ls] = ln[ix];
				ix++;
		}

		pntr[ts][ls] = '\0';
	}
	pntr[ts] = NULL;
	pntr[ts + ls] = NULL;

	return (pntr);
}
