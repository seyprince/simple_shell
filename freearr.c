#include "main.h"
/**
 * freearv - free arrays
 *@arv: array
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
