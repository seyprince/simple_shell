#include "main.h"
/**
 * _isatty - terminal checker
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}
