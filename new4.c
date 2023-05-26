#include "main.h"
/**
 * _EOF - End of File handler
 * @len: return value of getline function
 * @buff: buffer
 */
void _EOF(int len, char *buff)
{
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
		}
		free(buff);
		exit(0);
	}
}
