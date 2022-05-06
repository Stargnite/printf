#include "main.h"

/**
 * parse_binary - parse %b argument as a binary number
 * @buff_dest: string to format
 * @arg: number to format to
 * @buff_count: index of character
 * Return: new index
 */

int parse_binary(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int number = va_arg(arg, unsigned int);
	unsigned int tmp = number;
	int bin = 1;

	while (tmp > 1)
	{
		bin *= 2;
		tmp /= 2;
	}
	tmp = number;
	while (bin > 0)
	{
		buff_dest[buff_count] = ('0' + tmp / bin);
		tmp %= bin;
		bin /= 2;
		buff_count++;
	}
	return (buff_count);
}
