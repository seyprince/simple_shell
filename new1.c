#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitstring - makes array of pointers to words
 * @str: the string
 * @delim: the delimiter
 * Return: array of strings
 */
char **splitstring(char *str, const char *delim)
{
    int wn = 0;
    char **array = NULL;
    char *token;
    char *copy;

    copy = strdup(str);
    if (copy == NULL)
    {
        perror("_getenv");
        return (NULL);
    }

    token = strtok(copy, delim);
    while (token)
    {
        wn++;
        array = realloc(array, sizeof(char *) * wn);
        if (array == NULL)
        {
            perror("_getenv");
            free(copy);
            return (NULL);
        }
        array[wn - 1] = strdup(token);
        token = strtok(NULL, delim);
    }

    free(copy);
    return (array);
}
