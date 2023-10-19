#include "shell.h"
/**
 * main - Ethis is the main function of the shell
 * @ac: this are the number of arguments
 * @av: this are the argument vectors
 * Return: 0
 */
int main(int ac, char **av)
{
	char *in = NULL, **command = NULL;
	int status = 0, index = 0;
	(void)ac;

	while (1 != 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		in = input();
		if (in == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		command = tokenizer(in);
		comment_handler(&command);
		if (!command)
			continue;

		variable_replacer(command, status);

		if (_strcmp(command[0], "env") == 0)
			envi(command, &status);

		else if (_strcmp(command[0], "exit") == 0)
			exiter(command, av, &status, index);
		else
			status = executer(command, av, index);
	}
}
