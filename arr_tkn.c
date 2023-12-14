#include "shell.h"

/**
 * nm_tkn - counts the number of tokens in an array
 * tokenizes a string of user inputs and counts the numver of tokens
 * uses strtok
 * @usr_inp: user command string
 * @dlm: delimiter set for function
 *
 * Return: the number of tokens found size_t cnt_tkn.
 */
size_t nm_tkn(char *usr_inp, char *dlm)
{
	char *tkn;
	size_t cnt_tkn;

	tkn = strtok(usr_inp, dlm);
	for (cnt_tkn = 0; tkn != NULL; cnt_tkn++)
		tkn = strtok(NULL, dlm);

	return (cnt_tkn);
}

/**
 * arr_tkn - creates an array of tokens from the user input
 * creates an array of tokens from suer command
 * uses malloc to allocate memory
 * counts the number of tokens
 * @usr_inp: user command string
 * @dlm: delimeter set for function
 *
 * Return: pointer to array of tokens
 */
char **arr_tkn(char *usr_inp, char *dlm)
{
	char **arr_tkns;
	char *cp_inp, *tkn;
	size_t cnt_tkn, i_tkn, i_free;

	arr_tkns = NULL;
	ch_mllc(&cp_inp, strlen(usr_inp) + 1,
			"Malloc failure: malloc failure, cp_inp");
	strcpy(cp_inp, usr_inp);
	cnt_tkn = nm_tkn(cp_inp, dlm);

	arr_tkns = arr_mllc(arr_tkns, cnt_tkn + 1,
			"Error: malloc failure, arr_tkns");
	strcpy(cp_inp, usr_inp);
	tkn = strtok(cp_inp, dlm);
	for (i_tkn = 0; i_tkn < cnt_tkn; i_tkn++)
	{
		arr_tkns[i_tkn] = (char *)malloc(sizeof(char) *
				strlen(tkn) + 1);
		if (arr_tkns[i_tkn] == NULL)
		{
			for (i_free = 0; i_free < i_tkn; i_free++)
				free(arr_tkns[i_free]);
			free(cp_inp);
			free(arr_tkns);
			perror("Error: malloc failure, arr_tkns");
			return (NULL);
		}
		strcpy(arr_tkn[i_tkn], tkn);
		tkn = strtok(NULL, dlm);
	}
	free(cp_inp);
	arr_tkns[cnt_tkn] = NULL;
	return (arr_tkns);
}
