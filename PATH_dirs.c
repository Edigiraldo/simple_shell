#include "Holberton.h"

/**
 * PATH_dirs - function that gets the paths where
 * executable files might be.
 *
 * Return: array of paths.
 */

char **PATH_dirs(void)
{
	char *PATHS = NULL; /*PATH1:PATH2:...*/
	char *IND_PATH = NULL; /*PATH1*/
	char **PATH_arr = NULL;
	int size_ptr = sizeof(char *), i = 2;

	PATHS = _getenv("PATH");

	IND_PATH = strtok(PATHS, ":");

	PATH_arr = malloc(size_ptr * 2);
	/*if malloc == -1*/
	PATH_arr[0] = IND_PATH;
	IND_PATH = strtok(NULL, ":");
	while (IND_PATH != NULL)
	{
		PATH_arr = _realloc(PATH_arr, i * size_ptr, (i + 1) * size_ptr);
		PATH_arr[i - 1] = IND_PATH;
		IND_PATH = strtok(NULL, ":");
		i++;
	}
		PATH_arr[i - 1] = NULL;

	return (PATH_arr);
}
