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
	unsigned int bit, number;
	int MSB = 0;
	int i;

	number = va_arg(arg, unsigned int);
	for (i = INT_BITS; i > 0; i--)
	{
		bit = number >> (i - 1);
		bit = bit & 1;
		MSB = MSB | bit;
		if (MSB != 0 || i == 1)
		{
			buff_dest[buff_count] = ('0' + bit);
			buff_count++;
		}
	}
	return (buff_count);
}
