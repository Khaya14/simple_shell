#include "shell.h"

/**
 * r_alloc - this function is responsible for resizing a memory block
 * uses free and malloc
 * @mem_ptr: This is the pinter to a previously allocated block of memory
 * @prev_sz: This is the of the previously allocated memory in bytes
 * @nxt_sz: This is the size of the new memory block in bytes
 * Return: void
 */
void *r_alloc(void *mem_ptr, unsigned int prev_sz, unsigned int nxt_sz)
{
	void *bytes;
	unsigned int idx;
	char *cp_memptr, *space;

	if (nxt_sz == prev_sz)
		return (mem_ptr);

	if (mem_ptr == NULL)
	{
		bytes = malloc(nxt_sz);
		if (bytes == NULL)
			return (NULL);

		return (bytes);
	}

	if (nxt_sz == 0 && mem_ptr != NULL)
	{
		free(mem_ptr);
		return (NULL);
	}

	cp_memptr = mem_ptr;
	bytes = malloc(sizeof(*cp_memptr) * nxt_sz);
	if (bytes == NULL)
	{
		free(mem_ptr);
		return (NULL);
	}

	space = bytes;

	for (idx = 0; idx < prev_sz && idx < nxt_sz; idx++)
		space[idx] = *cp_memptr++;

	free(mem_ptr);
	return (bytes);
}

/**
 * create_lnptr - this function will assign and reassign a pointer to a
 * line pointer variable
 * @lnptr: This a pointer to a buffer that will store the string of commands
 * @sz: This is the size of the line pointer variable
 * @_buf: This is a string that must be assigned to the line pointer variable
 * @szb: this is the size of the buffer string
 * Return: void
 */
void create_lnptr(char **lnptr, size_t *sz, size_t szb, char *_buf)
{
	if (*lnptr == NULL)
	{
		if (szb > 120)
			*sz = szb;
		else
			*sz = 120;
		*lnptr = _buf;
	}
	else
	{
		strcpy(*lnptr, _buf);
		free(_buf);
	}

}

/**
 * _get_line - This function is able to read an inout from a stream
 * @lnptr: This is buffer that stores the string read from the stream
 * @sz: this is the size of the string buffer
 * @input_stream: This is the stream that the function will read from
 *
 * Return: The number of bytes read from the stream
 */
ssize_t _get_line(char **lnptr, size_t *sz, FILE *input_stream)
{
	static ssize_t inp;
	ssize_t res;
	char *_buf, chr;
	int nm;

	if (inp == 0)
		fflush(input_stream);
	else
		return (-1);
	inp = 0;

	_buf = malloc(sizeof(char) * 120);
	if (!_buf)
		return (-1);
	chr = 'x';
	while (chr != '\n')
	{
		nm = read(STDIN_FILENO, &chr, 1);
		if (nm == -1 || (nm == 0 && inp == 0))
		{
			free(_buf);
			return (-1);
		}
		if (nm == 0 && inp != 0)
		{
			inp++;
			break;
		}
		if (inp >= 120)
			_buf = r_alloc(_buf, inp, inp + 1);
		_buf[inp] = chr;
		inp++;
	}
	_buf[inp] = '\0';
	create_lnptr(lnptr, sz, inp, _buf);
	res = inp;
	if (nm != 0)
		inp = 0;
	return (res);
}
