#include "Holberton.h"

/**
 * call_command - takes the arguments to a function
 * call that function and pass that arguments.
 *
 * @argv: arguments to function.
 * @PATH_arr: array of paths for free.
 * @lineptr: command inserted for user.
 */

void call_command(char *av[], char *argv[], char **PATH_arr, char *lineptr, char **environ, int *statu)
{
	pid_t cpid = 0;
	char *command_path = NULL;
	int free_command_path = 0;
	int status;

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
		if (execve(command_path, argv, environ) == -1)
			perror(av[0]);   /* execve() only returns on error */

		free(lineptr);
		free(argv);
		free(PATH_arr[0] - 5);
		free(PATH_arr);
		if (free_command_path == 1)
			free(command_path);
		exit(0);
	}
	if (cpid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			*statu = WEXITSTATUS(status);
		}
		if (free_command_path == 1)
			free(command_path);
		free(argv);
		/*free(PATH_arr);*/
		free(lineptr);
		print_prompt();
	}
}
