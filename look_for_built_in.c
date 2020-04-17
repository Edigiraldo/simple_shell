#include "Holberton.h"

/**
 * look_for_built_in - looks for builtin command and call
 * a function according to that.
 *
 * @lineptr: pointer for free.
 * @argv: pointer for free.
 * @PATH_arr: pointer for free.
 *
 * Return: 1 if a builtin command was found, else 0.
 */

int look_for_built_in(char *lineptr, char **argv, char **PATH_arr,
	 char **environ, int *status)
{
	int command = 0, letter = 0;

	char *built_ins[] = {"exit", "env", NULL};

	void (*func_ptr[])(char *, char **, char **, char **, int *)
	= {Exit, Env, NULL};

	while (built_ins[command] != NULL)
	{
		letter = 0;
		while (built_ins[command][letter] != '\0')
		{
			if (built_ins[command][letter] != argv[0][letter])
				break;
			letter++;
		}
		if (built_ins[command][letter] == '\0' && argv[0][letter] == '\0')
		{
			func_ptr[command](lineptr, argv, PATH_arr, environ, status);
			return (1);
		}
		command++;
	}

	return (0);
}
