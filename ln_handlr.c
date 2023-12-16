#include "shell.h"

/**
 * ln_handlr - gets line from inout and partitions it
 * @ln: arg 1
 * @rd: arg 2
 *
 */
void ln_handlr(char **ln, ssize_t rd)
{
	char *old_ln, *nw_ln;
	char _prev, _curr, _next;
	size_t _i, _j;
	ssize_t nw_len;

	nw_len = getsnew_len_(*ln);
	if (nw_len == rd - 1)
		return;
	nw_ln = malloc(nw_len + 1);
	if (!nw_ln)
		return;
	_j = 0;
	old_ln = *ln;
	for (_i = 0; old_ln[_i]; _i++)
	{
		_curr = old_ln[_i];
		_next = old_ln[_i + 1];
		if (_i != 0)
		{
			_prev = old_ln[_i - 1];
			if (_curr == ';')
			{
				if (_next == ';' && _prev != ' ' && _prev != ';')
				{
					nw_ln[_j++] = ' ';
					nw_ln[_j++] = ';';
					continue;
				}
				else if (_prev == ';' && _next != ' ')
				{
					nw_ln[_j++] = ';';
					nw_ln[_j++] = ' ';
					continue;
				}
				if (_prev != ' ')
					nw_ln[_j++] = ' ';
				nw_ln[_j++] = ';';
				if (_next != ' ')
					nw_ln[_j++] = ' ';
				continue;
			}
			else if (_curr == '&')
			{
				if (_next == '&' && _prev != ' ')
					nw_ln[_j++] = ' ';
				else if (_prev == '&' && _next != ' ')
				{
					nw_ln[_j++] = '&';
					nw_ln[_j++] = ' ';
					continue;
				}
			}
			else if (_curr == '|')
			{
				if (_next == '|' && _prev != ' ')
					nw_ln[_j++]  = ' ';
				else if (_prev == '|' && _next != ' ')
				{
					nw_ln[_j++] = '|';
					nw_ln[_j++] = ' ';
					continue;
				}
			}
		}
		else if (_curr == ';')
		{
			if (_i != 0 && old_ln[_i - 1] != ' ')
				nw_ln[_j++] = ' ';
			nw_ln[_j++] = ';';
			if (_next != ' ' && _next != ';')
				nw_ln[_j++] = ' ';
			continue;
		}
		nw_ln[_j++] = old_ln[_i];
	}
	nw_ln[_j] = '\0';

	free(*ln);
	*ln = nw_ln;
}

/**
 * getsnew_len_ - gets the new length of the new line
 * @ln: arg 1
 *
 * Return: length of new line
 */
ssize_t getsnew_len_(char *ln)
{
	size_t _i;
	ssize_t nw_len = 0;
	char _curr, _next;

	for (_i = 0; ln[_i]; _i++)
	{
		_curr = ln[_i];
		_next = ln[_i + 1];
		if (_curr == '#')
		{
			if (_i == 0 || ln[_i - 1] == ' ')
			{
				ln[_i] = '\0';
				break;
			}
		}
		else if (_i != 0)
		{
			if (_curr == ';')
			{
				if (_next == ';' && ln[_i - 1] != ' ' && ln[_i - 1] != ';')
				{
					nw_len += 2;
					continue;
				}
				else if (ln[_i - 1] == ';' && _next != ' ')
				{
					nw_len += 2;
					continue;
				}
				if (ln[_i - 1] != ' ')
					nw_len++;
				if (_next != ' ')
					nw_len++;
			}
			else
				logic(&ln[_i], &nw_len);
		}
		else if (_curr == ';')
		{
			if (_i != 0 && ln[_i - 1] != ' ')
				nw_len++;
			if (_next != ' ' && _next != ';')
				nw_len++;
		}
		nw_len++;
	}
	return (nw_len);
}

/**
 * logic - handles logic operations
 * @ln: arg 1
 * @nw_len: arg 2
 */
void logic(char *ln, ssize_t *nw_len)
{
	char _prev, _curr, _next;

	_prev = *(ln - 1);
	_curr = *ln;
	_next = *(ln + 1);

	if (_curr == '&')
	{
		if (_next == '&' && _prev != ' ')
			(*nw_len)++;
		else if (_prev == '&' && _next != ' ')
			(*nw_len)++;
	}
	else if (_curr == '|')
	{
		if (_next == '|' && _prev != ' ')
			(*nw_len)++;
		else if (_prev == '|' && _next != ' ')
			(*nw_len)++;
	}
}
