#include "main.h"
/**
 * execute - command exercusion
 * @argv: array
 */

void execute(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
