#include "shell.h"
/**
 * tokenizer- This is used to tokenize
 * @input: this is the input
 * Return: pointer to a pointer.
 */
char **tokenizer(char *input)
{
	int i = 0, j = 0;
	char *token, *tmp, **arr = NULL, delimeters[] = " \n\t";

	if (input == NULL)
		return (NULL);

	tmp = _strdup(input);
	token = strtok(tmp, delimeters);
	if (!token)
	{
		free(input);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, delimeters);
	}
	free(tmp);
	arr = malloc(sizeof(char *) * (j + 1));
	token = strtok(input, delimeters);
	while (token)
	{
		arr[i++] = _strdup(token);
		token = strtok(NULL, delimeters);
	}
	free(input);
	arr[i] = NULL;
	return (arr);
}
