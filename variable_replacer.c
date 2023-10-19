#include "shell.h"
/**
 * variable_replacer - a function
 * @command: a double pointer
 * @status: integer
 */
void variable_replacer(char **command, int status)
{
	int i;
	char c;
	char *replace = NULL, *ptr;

	for (i = 0; command[i]; i++)
	{
		if (command[i][0] == '$')
		{
			c = command[i][1];
			if (c == '?')
				replace = _itoa(status);

			else if (c == '$')
				replace = _itoa((int)getpid());
			else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				ptr = command[i];
				ptr++;
				replace = get_environ(ptr);
				if (!replace)
					replace = strdup("");
			}

			if (replace != NULL)
				free(command[i]), command[i] = replace;
		}
	}
}
