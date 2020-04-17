#include "Holberton.h"

/**
 * Env - env builtin command, prints environment.
 *
 * @lineptr: pointer for free.
 * @argv: pointer for free.
 * @PATH_arr: pointer for free.
 */

void Env(char *lineptr, char **argv, char **PATH_arr, char **environ, int *status)
{
	int i = 0;
	(void) lineptr;
	(void) argv;
	(void) PATH_arr;
	(void) status; 

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
/* ssize_t write(int fd, const void *buf, size_t count) */
