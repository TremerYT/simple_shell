#include "shell.h"
/**
 * is_num - this is a function
 * @str: this is a pointer to a pointer
 * Return: 0, 1
 */
int is_num(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _atoi - This ia the atoi function
 * @str: This is a pointer to a pointer
 * Return: number
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
/**
 * string_reverser - a function
 * @str: this is a pointer to apointer
 * @length: this is a length
 */
void string_reverser(char *str, int length)
{
	char tmp;
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * _itoa - This is the itoa fucdfbgnhk
 * @m: this is a number
 * Return: nothing
 */
char *_itoa(int m)
{
	char buffer[20];
	int i = 0;

	if (m == 0)
		buffer[i++] = '0';
	else
	{
		while (m > 0)
		{
			buffer[i++] = (m % 10) + '0';
			m /= 10;
		}
	}

	buffer[i] = '\0';
	string_reverser(buffer, i);

	return (_strdup(buffer));
}
