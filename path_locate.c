#include "shell.h"

/**
 * locate_cmd - finds a command in a specific path
 * @cmd: the command from the user
 *
 * Return: NULL if the command cannot be found, or if fail
 */
char *locate_cmd(char *cmd)
{
	char **_path, *_buf;
	list_d *directories, *head;
	struct stat _st;

	_path = _gets_env("PATH");
	if (!_path || !(*_path))
		return (NULL);

	directories = path_direct(*_path + 5);
	head = directories;

	while (directories)
	{
		_buf = malloc(strlen(directories->dir_name) + strlen(cmd) + 2);
		if (!_buf)
			return (NULL);

		strcpy(_buf, directories->dir_name);
		strcat(_buf, "/");
		strcat(_buf, cmd);

		if (stat(_buf, &_st) == 0)
		{
			free_ls(head);
			return (_buf);
		}

		directories = directories->next;
		free(_buf);
	}

	free_ls(head);

	return (NULL);
}
/**
 * _full_pathname - creates afull pathname, while replacing special characters
 * in the string
 * @_path: this is the pathname to be evaluated
 *
 * Return: pointer to a copt of the pathname
 */
char *_full_pathname(char *_path)
{
	int _i, ln = 0;
	char *cp_path, *_pwd;

	_pwd = *(_gets_env("PWD")) + 4;
	for (_i = 0; _path[_i]; _i++)
	{
		if (_path[_i] == ':')
		{
			if (_path[_i + 1] == ':' || _i == 0 || _path[_i + 1] == '\0')
				ln += strlen(_pwd) + 1;
			else
				ln++;
		}
		else
			ln++;
	}
	cp_path = malloc(sizeof(char) * (ln + 1));
	if (!cp_path)
		return (NULL);
	cp_path[0] = '\0';
	for (_i = 0; _path[_i]; _i++)
	{
		if (_path[_i] == ':')
		{
			if (_i == 0)
			{
				strcat(cp_path, _pwd);
				strcat(cp_path, ":");
			}
			else if (_path[_i + 1] == ':' || _path[_i + 1] == '\0')
			{
				strcat(cp_path, ":");
				strcat(cp_path, _pwd);
			}
			else
				strcat(cp_path, ":");
		}
		else
		{
			strncat(cp_path, &_path[_i], 1);
		}
	}
	return (cp_path);
}
/**
 * path_direct - creates a list of tokens of the pathnames
 * stores them in a linked list
 * @_path: The full path name
 *
 * Return: a pointer to the linked list that is already initialized
 */
list_d *path_direct(char *_path)
{
	int _i;
	char **directories, *cp_path;
	list_d *head = NULL;

	cp_path = _full_pathname(_path);
	if (!cp_path)
		return (NULL);
	directories = strtok_(cp_path, ":");
	free(cp_path);
	if (!directories)
		return (NULL);

	for (_i = 0; directories[_i]; _i++)
	{
		if (end_node(&head, directories[_i]) == NULL)
		{
			free_ls(head);
			free(directories);
			return (NULL);
		}
	}

	free(directories);

	return (head);
}
