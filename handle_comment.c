#include "monty.h"
/**
 * handle_comment - handles comments
 * @str: the string which contains comments
 * Return: the string
 */

char *handle_comment(char *str)
{
	int i;

	if (str == NULL)
		return (str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '#')
		{
			return (str);
		}
		else if (str[i] != ' ' && str[i] == '#')
		{
			str[i] = '\0';
			return (str);
		}
	}

	return (str);
}
