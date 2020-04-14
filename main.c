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
	(void)ac;
	(void)av;

	printf("#cisfun$ ");
	PATH_arr = PATH_dirs();
	while (getline(&lineptr, &n, stdin) != -1)
	{
		argv = split_arguments(lineptr);
		if (look_for_built_in(lineptr, argv, PATH_arr) == 1)
		{
			free(argv);
			free(lineptr);
			lineptr = NULL;
			n = 0;
			printf("#cisfun$ ");
			continue;
		}
		call_command(argv, PATH_arr, lineptr);
		lineptr = NULL;
		n = 0;
	}
	free(PATH_arr);
	free(lineptr);
	exit(EXIT_FAILURE);

	return (0);
}
