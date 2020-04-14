#include "Holberton.h"

/**
 * Env - env builtin command, prints environment.
 *
 * @lineptr: pointer for free.
 * @argv: pointer for free.
 * @PATH_arr: pointer for free.
 */

void Env(char *lineptr, char **argv, char **PATH_arr)
{
	extern char **environ;
	int i = 0;
	(void) lineptr;
	(void) argv;
	(void) PATH_arr;

	while (environ[i] != NULL)
		printf("%s\n", environ[i++]);
}
