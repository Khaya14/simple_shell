#include "shell.h"

/**
 * ch_mllc - allocates memoray for a string buffer
 * @_buf: the string that is passed
 * @mllc_sz: this is the size of the allocated memory
 * @msg: an error message to be printed in failure
 *
 * Return: the pointer to allocated memory
 */
char *ch_mllc(char **_buf, size_t mllc_sz, char *msg)
{
	*_buf = (char *)malloc(mllc_sz * sizeof(char));
	if (_buf == NULL)
	{
		perror(msg);
		return (NULL);
	}
	return (*_buf);
}

/**
 * arr_mllc - allocates memory for an array of tokens
 * The function uses malloc to allocate memory for an array
 * @arr: the array that has to be allocated memory
 * @mllc_sz: size of the memory allocated
 * @msg: error message printed on failure
 * Return: pointer to new memory allocated
 */
char **arr_mllc(char **arr, size_t mllc_sz, char *msg)
{
	arr = (char **)malloc(sizeof(char *) * mllc_sz);
	if (arr == NULL)
	{
		perror(msg);
		return (NULL);
	}

	return (arr);
}
