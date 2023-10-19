#include "shell.h"
/**
 * get_environ- this gets the environmet
 * @var: this is a pointer to the variable
 * Return: this returns a pointer
 */
char *get_environ(char *var)
{
	int i;
	char *key, *env_value, *tmp;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			env_value = _strdup(strtok(NULL, "\n"));
			free(tmp);
			return (env_value);
		}
		free(tmp);
	}
	return (NULL);
}
/**
 * free_arr - this is a function to free
 * @arr: this ia n array
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
/**
 * error_printer - a function
 * @name: a  pointer
 * @ind: a pointer
 * @cmd: a pointer
 */
void error_printer(char *name, int ind, char *cmd)
{
	char *index, message[] = "ERROR: not found\n";

	index = _itoa(ind);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, message, _strlen(message));
	free(index);
}
