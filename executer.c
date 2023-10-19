#include "shell.h"
/**
 * executer - this is the function to execute
 * @command: this is a pointer to apointer
 * @argv: this is the argument vector
 * @ind: index
 * Return: satattattatata
 */
int executer(char **command, char **argv, int ind)
{
	pid_t my_baby;
	char *path = NULL;
	int status;

	path = path_geter(command[0]);
	if (!path)
	{
		error_printer(argv[0], ind, command[0]);
		free_arr(command);
		return (127);
	}

	my_baby = fork();
	if (my_baby == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			free(path);
			free_arr(command);
		}
	}
	else
	{
		waitpid(my_baby, &status, 0);
		free(path);
		free_arr(command);
	}

	return (WEXITSTATUS(status));
}
