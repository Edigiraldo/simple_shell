#include <stdio.h>
#include <stdlib.h>

/**
 * int_str - converts int to string
 * @n: interger to convert
 *
 * Return: string of numbers
 */

char *int_str(unsigned int n)
{
	char *str;
	unsigned int i = 0;
	unsigned int num = n;

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
	return (str);
}

int main(void)
{
	printf("%s\n", int_str(105));

	return (0);
}
