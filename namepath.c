#include "main.h"
/**
 * _which - pathname finder
 * @filename: file name
 * @head: linked list head
 * Return: filename or NULL
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = concat_all(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}
