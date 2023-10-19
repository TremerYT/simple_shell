#include "shell.h"

/**
 * envi - This is the function of the environment
 * @command: This is a pointer to a pointer
 * @status: This is an pleaseeeeeeeee
 */
void envi(char **command, int *status)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	free_arr(command);
}
/**
 * exiter - this is the exiter function
 * @command: this is a pointer to a pointer
 * @argv: this is a pointer to a pointer
 * @status: it is of integer variable
 * @ind: llllll
 */
void exiter(char **command, char **argv, int *status, int ind)
{
	char *index;
	char message[] = "ERROR: Illegal number: ";
	int exit_value = (*status);

	if (command[1])
	{
		if (!is_num(command[1]))
		{
			index = _itoa(ind);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, message, _strlen(message));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			(*status) = 2;
			free(index);
			free_arr(command);

			return;
		}
		else
			exit_value = _atoi(command[1]);
	}
	free_arr(command);
	exit(exit_value);
}
