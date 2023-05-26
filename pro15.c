#include "main.h"

/**
 * prompt - display prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - error displays based on cmd
 * @input: input
 * @counter: shell loop
 * @argv: name
 * Return: nothing
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
