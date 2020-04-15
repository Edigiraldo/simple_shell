#include "Holberton.h"

/**
* print_prompt - Function to print prompt
*Return: Nothing.
*/

void print_prompt(void)
{
    if (isatty(0))
    {
        write(1, "#cisfun$ ", 9);
    }
}