#include "main.h"

/**
 * parse_char - prints a character to stdout
 * @buff_dest: buffer
 * @arg: argument list
 * @buff_count: index of buffer
 * Return: buffer index
 */

int parse_char(char *buff_dest, va_list arg, int buff_count)
{
	char c = va_arg(arg, int);

	buff_dest[buff_count] = c;
	return (++buff_count);
}
