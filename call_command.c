#include "Holberton.h"

/**
 * call_command - takes the arguments to a function
 * call that function and pass that arguments.
 *
 * @argv: arguments to function.
 * @PATH_arr: array of paths for free.
 * @lineptr: command inserted for user.
 */

void call_command(char *argv[], char **PATH_arr, char *lineptr)
{
	pid_t cpid = 0;
	int status = 0;
	char *command_path = NULL;
	int free_command_path = 0;

	command_path = look_for_path(argv[0], PATH_arr);
	if (command_path != NULL)
	{
		argv[0] = command_path;
		free_command_path = 1;
	}

	cpid = fork();
	if (cpid == 0)
	{
		execve(argv[0], argv, NULL);

		free(lineptr);
		if (free_command_path == 1)
			free(argv[0]);
		free(argv);
		free(PATH_arr);
		perror("./shell");   /* execve() only returns on error */
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
			free(argv[0]);
		free(argv);
		/*free(PATH_arr);*/
		free(lineptr);
		printf("#cisfun$ ");
	}
}
