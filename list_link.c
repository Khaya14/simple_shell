#include "shell.h"

/**
 * end_node - concatenates a linked list with a node at the end
 * @head: head of linked list pointer
 * @directory: new node's path in the directory
 *
 * Return: NULL on error, else new node pointer
 */
list_d *end_node(list_d **head, char *directory)
{
	list_d *node_nw = malloc(sizeof(list_d));
	list_d *_end;

	if (!node_nw)
		return (NULL);

	node_nw->dir_name = directory;
	node_nw->next = NULL;

	if (*head)
	{
		_end = *head;
		while (_end->next != NULL)
			_end = _end->next;
		_end->next = node_nw;
	}
	else
		*head = node_nw;

	return (node_nw);
}

/**
 * free_ls - frees a list_d list
 * @head: The head of the list
 */
void free_ls(list_d *head)
{
	list_d *node;

	while (head)
	{
		node = head->next;
		free(head->dir_name);
		free(head);
		head = node;
	}
}
