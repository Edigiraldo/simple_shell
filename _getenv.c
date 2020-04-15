#include "Holberton.h"

char *_getenv(const char *name)
{
	extern char **environ;
	char *envi = NULL;
	int i = 0, j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while ((environ[i][j] != '=') && (name[j] != '\0'))
		{
			if (environ[i][j] != name[j])
			{
				break;
			}
			j++;
		}

		if ((environ[i][j] == '=') && (name[j] == '\0'))
		{
			strtok(environ[i], "=");
			envi = strtok(NULL, "=");
			return (envi);
		}
		else
			i++;
	}

	return (NULL);
}
