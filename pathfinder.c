#include "shell.h"
/**
 * path_geter - This is the get path function
 * @command: This is a pointer to a pointer
 * Return: NULL, or path
 */
char *path_geter(char *command)
{
	int i;
	char *path, *directory, *PATH;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				path = _strdup(command);
				return (path);
			}
			return (NULL);
		}
	}
	PATH = get_environ("PATH");
	if (PATH == NULL)
		return (NULL);

	directory = strtok(PATH, ":");
	while (directory)
	{
		path = malloc(_strlen(directory) + _strlen(command) + 2);

		_strcpy(path, directory);
		_strcat(path, "/");
		_strcat(path, command);
		if (stat(path, &st) == 0)
		{
			free(PATH);
			return (path);
		}
		free(path);
		path = NULL;
		directory = strtok(NULL, ":");
	}
	free(PATH);
	return (NULL);
}
