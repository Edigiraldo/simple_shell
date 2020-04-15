#include "Holberton.h"

/**
 * strings_concat - concatenate two strings.
 *
 * @PATH: Firts string.
 * @command: Second string.
 *
 * Return: concatened strings.
 */

char *strings_concat(char *PATH, char *command)
{
	size_t PATH_len = _strlen(PATH);
	size_t command_len = _strlen(command);
	size_t dest_len = PATH_len + command_len;
	size_t i;
	char *concatened = NULL;

	concatened = malloc((dest_len + 2) * sizeof(char));
	/* if malloc == -1 */
	for (i = 0; i < PATH_len; i++)
		concatened[i] = PATH[i];
	concatened[i] = '/';

	for (i = 0 ; i < command_len; i++)
		concatened[PATH_len + 1 + i] = command[i];

	concatened[PATH_len + 1 + i] = '\0';

	return (concatened);
}
