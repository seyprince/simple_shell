#include "main.h"
/**
 *  _prerror - print error
 * @argv: name
 * @c: count
 * @cmd: command
 * Return: nothing
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
