#include "Holberton.h"

void print_error(char *message, int *parameter, char *message2)
{
	char *str_parameter = NULL;

	if (message != NULL)
		write(2, message, _strlen(message));
	if (parameter != NULL)
	{
		str_parameter = int_str(*parameter);
		write(2, str_parameter, _strlen(str_parameter));
		free(str_parameter);
	}
	if (message2 != NULL)
		write(2, message2, _strlen(message2));
}
