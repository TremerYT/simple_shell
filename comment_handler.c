#include "shell.h"
/**
 * comment_handler - this is a function to handle comments
 * @command: this is a pointer to a pointer
 */
void comment_handler(char ***command)
{
	int i, comms;

	if (!(*command))
		return;

	comms = 0;

	for (i = 0; (*command)[i]; i++)
	{
		if ((*command)[i][0] == '#')
		{
			comms = 1;
			break;
		}
	}
	if (comms == 1)
	{
		while ((*command)[i])
		{
			free((*command)[i]);
			(*command)[i] = NULL;
			i++;
		}
	}
	if ((*command)[0] == NULL)
	{
		free((*command));
		(*command) = NULL;
	}
}
