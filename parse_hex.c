#include "main.h"

/**
 * parse_hex - substitute %x by unsigned int arg num
 * @buff_dest: string to format
 * @arg: va_list arg to change
 * @buff_count: index of buffer
 * Return: new index
 */

int parse_hex(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int number = va_arg(arg, unsigned int);
	unsigned int tmp = number;
	int hex = 1;

	while (tmp > 15)
	{
		hex *= 16;
		tmp /= 16;
	}
	tmp = number;
	while (hex > 0)
	{
		buff_dest[buff_count] = (tmp / hex < 9) ?
			(tmp / hex + '0') : ('a' + tmp / hex - 10);
		tmp %= hex;
		hex /= 16;
		buff_count++;
	}
	return (buff_count);
}

/**
 * parse_X - sub %X by unsigned int arg num
 * @buff_dest: string to change
 * @arg: va_list arg to change
 * @buff_count: index of buffer
 * Return: new index
 */

int parse_X(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int number = va_arg(arg, unsigned int);
	unsigned int tmp = number;
	int hex = 1;

	while (tmp > 15)
	{
		hex *= 16;
		tmp /= 16;
	}

	tmp = number;
	while (hex > 0)
	{
		buff_dest[buff_count] = (tmp / hex < 9) ?
			(tmp / hex + '0') : ('A' + tmp / hex - 10);
		tmp %= hex;
		hex /= 16;
		buff_count++;
	}
	return (buff_count);
}
