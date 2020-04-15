#include "Holberton.h"

/**
 * call_command - takes the arguments to a function
 * call that function and pass that arguments.
 *
 * @argv: arguments to function.
 * @PATH_arr: array of paths for free.
 * @lineptr: command inserted for user.
 */

void call_command(char *av[], char *argv[], char **PATH_arr, char *lineptr, char **environ)
{
	pid_t cpid = 0;
	int status = 0;
	char *command_path = NULL;
	int free_command_path = 0;

	command_path = look_for_path(argv[0], PATH_arr);
	if (command_path != NULL)
	{
		free_command_path = 1;
	}
	else
		command_path = argv[0];

	cpid = fork();
	if (cpid == 0)
	{
		execve(command_path, argv, environ);

		free(lineptr);
		free(argv);
		free(PATH_arr);
		perror(av[0]);   /* execve() only returns on error */
		if (free_command_path == 1)
			free(command_path);
		exit(EXIT_FAILURE);
	}
	else if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (free_command_path == 1)
			free(command_path);
		free(argv);
		/*free(PATH_arr);*/
		free(lineptr);
		print_prompt();
	}
}
