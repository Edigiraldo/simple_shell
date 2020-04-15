#include "Holberton.h"

/**
 * main - main function for the shell.
 *
 * @ac: number of arguments passed to main function.
 * @av: Arguments passed to main function.
 *
 * Return: returns 0 on success.
 */

int main(int ac, char *av[])
{
	char *lineptr = NULL;
	char **argv = NULL;
	char **PATH_arr = NULL;
	size_t n = 0;
	extern char **environ;
	(void)ac;
	(void)av;

	PATH_arr = PATH_dirs();
	printf("#cisfun$ ");
	while (getline(&lineptr, &n, stdin) != -1)
	{
		argv = split_arguments(lineptr);

		if (argv[0] == NULL || look_for_built_in(lineptr, argv, PATH_arr, environ) == 1)
		{
			free(argv);
			free(lineptr);
			lineptr = NULL;
			n = 0;
			printf("#cisfun$ ");
			continue;
		}
		call_command(av, argv, PATH_arr, lineptr, environ);
		lineptr = NULL;
		n = 0;
	}
	write(1, "\n", 1);
	free(lineptr);
	free(PATH_arr);
	exit(EXIT_FAILURE);

	return (0);
}
