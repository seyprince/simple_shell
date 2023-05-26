#include "main.h"
/**
 * sig_handler - Ctrl C signal handler
 * @sig_num: signal number
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}
