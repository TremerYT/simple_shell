#include "shell.h"
/**
 * _strdup - This is the string duplicate function
 * @str: this is a pointer to a pointer
 * Return: a pointer
 */
char *_strdup(const char *str)
{
	char *pointer;
	int i, length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	pointer = malloc(sizeof(char) * (length + 1));
	if (pointer == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		pointer[i] = str[i];
	return (pointer);
}
/**
 * _strcmp - this is a string compare function
 * @s1: this is string 1
 * @s2: this is string 2
 * Return: a pointer
 */
int _strcmp(char *s1, char *s2)
{
	int comp;

	comp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		comp = (int)*s1 - (int)*s2;
	}
	return (comp);
}
/**
 * _strlen - this used to find length
 * @s: this is the string
 * Return: length of string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}
/**
 * _strcat- this is used to concatenate a string
 * @dest: this is a pointer
 * @src: this is a pointer
 * Return: this is a pointer
 */
char *_strcat(char *dest, char *src)
{
	char *i = dest;

	while (*i)
		i++;

	while (*src)
	{
		*i = *src;
		i++;
		src++;
	}
	*i = '\0';
	return (dest);
}
/**
 * _strcpy -this is a sfunction to copy a string
 * @dest: this is a apointree
 * @src: this is a pointer
 * Return: i do not know
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
