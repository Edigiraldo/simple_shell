#include "Holberton.h"

/**
 * Exit - exit builtin command.
 *
 * @lineptr: pointer for free.
 * @argv: arguments for exit.
 * @PATH_arr: pointer for free.
 */

void Exit(char *lineptr, char **argv, char **PATH_arr, __attribute__((unused)) char **environ)
{
	int i = 1, num = 0;

	if (argv[1] != NULL && argv[2] != NULL)
	{
		write(2, "-hsh: exit: too many arguments\n", _strlen("-hsh: exit: too many arguments\n"));
		return;
	}
	free(PATH_arr);
	if (argv[1] != NULL)
	{       num = _atoi(argv[1]);
		if (num != 0)
		{       free(argv), free(lineptr);
			exit(num);
		}
		else if (argv[1][0] == '0')
		{
			while (argv[1][i] != '\0')
			{
				if (argv[1][i] != '0')
					break;
				i++;
			}
			if (argv[1][i] == '\0')
			{       free(argv), free(lineptr);
				exit(0);
			}
			else
			{write(2, "-hsh: exit: %s: numeric argument required\n", _strlen("-hsh: exit: %s: numeric argument required\n"));
				free(argv), free(lineptr);
				exit(0);
			}
		}
		else
		{write(2, "-hsh: exit: %s: numeric argument required\n", _strlen("-hsh: exit: %s: numeric argument required\n"));
			free(argv), free(lineptr);
			exit(0);
		}
	}
	else
		free(argv), free(lineptr), exit(0);
}
