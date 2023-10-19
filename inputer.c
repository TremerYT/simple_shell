#include "shell.h"
/**
 * input - This should allow user to input
 * Return: input
 */
char *input(void)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t n;

	n = getline(&input, &length, stdin);
	if (n == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
