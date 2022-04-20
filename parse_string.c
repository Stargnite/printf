#include "main.h"

/**
 * parse_string - outputs the string to stdout
 * @buff_dest: character string
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: number of characters
 */

int parse_string(char *buff_dest, va_list arg, int buff_count)
{
	char *value;
	int i = 0;

	value = va_arg(arg, char *);
	if (value == NULL)
		value = "(null)";
	if (value[0] == '\0')
	{
		buff_dest[buff_count] = '\0';
		buff_count++;
	}
	while (value[i] != '\0')
	{
		buff_dest[buff_count] = value[i];
		i++;
		buff_count++;
	}
	return (buff_count);
}
