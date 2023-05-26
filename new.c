#include "main.h"
#include <unistd.h>

/**
 * main - Shell
 * Return: 0
 */
int main(void)
{
    ssize_t len = 0;
    char *buff = NULL, *value, *pathname, **arv;
    size_t size = 0;
    list_path *head = NULL;
    void (*f)(char **);

    signal(SIGINT, sig_handler);
    while (len != EOF)
    {
        if (isatty(STDIN_FILENO))
        {
            len = getline(&buff, &size, stdin);
            if (len == EOF)
                break;
        }
        
        arv = splitstring(buff, " \n");
        if (arv == NULL)
        {
            _puts("Error: Failed to split input string\n");
            continue;
        }
        if (arv[0] == NULL)
        {
            free(arv);
            continue;
        }
        value = _getenv("PATH");
        if (value == NULL)
        {
            _puts("Error: Failed to retrieve PATH environment variable\n");
            free(arv);
            continue;
        }
        head = linkpath(value);
        if (head == NULL)
        {
            _puts("Error: Failed to create linked list of PATH directories\n");
            free(arv);
            continue;
        }
        pathname = _which(arv[0], head);
        f = checkbuild(arv);
        if (f)
        {
            free(buff);
            f(arv);
        }
        else if (!pathname)
            execute(arv);
        else if (pathname)
        {
            free(arv[0]);
            arv[0] = pathname;
            execute(arv);
        }
        free(arv);
    }

    free_list(head);
    free(buff);
    return (0);
}
