#include "Holberton.h"

/**
 * look_for_path - look for paths where command
 * might be.
 *
 * @argv0: command.
 * @PATH_arr: Posible paths.
 *
 * Return: NULL if path is as passed or if the path is not found
 * the path if it was found.
 */

char *look_for_path(char *argv0, char **PATH_arr)
{
	struct stat buf;
	char *command_path = NULL;
	int i = 0;

	if (stat(argv0, &buf) != 0)
	{
		while (PATH_arr[i] != NULL)
		{
			command_path = strings_concat(PATH_arr[i], argv0);
			if (stat(command_path, &buf) == 0)
				break;
			else if (PATH_arr[i + 1] == NULL)
			{
				free(command_path);
				command_path = NULL;
			}
			else
				free(command_path);
			i++;
		}
	}
	else
		command_path = NULL;

	return (command_path);
}
