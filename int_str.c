#include "Holberton.h"

/**
 * int_str - converts int to string
 * @n: interger to convert
 *
 * Return: string of numbers
 */

char *int_str(int n)
{
	char *str;
	int i = 0;
	int num = n;
	int negative = 0;

	if (num < 0)
	{
		n *= -1;
		num = n;
		i++;
		negative = 1;
	}

	if (num == 0)
		i++;

	while (num > 0)
	{
		num /= 10;
		i++;
	}

	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;

	while (i >= 0)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}

	if (negative == 1)
		str[0] = '-';

	return (str);
}
