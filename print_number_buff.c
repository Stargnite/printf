#include "main.h"

/**
 * print_number - copy given int to buffer serially
 * @n: int to print
 * @buffer: buffer being copied to print
 * @buflen: length of buffer
 * @bufpos: index of caracters in the buffer
 *
 * Return: number of characters printed
 */

int print_number(int n, char buffer[], int *buflen, int *bufpos)
{
	int chars;
	int sign_print;

	chars = sign_print = 0;
	if (n == 0)
	{
		buffer[*bufpos] = '0';
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		return (1);
	}
	else if (n > 0)
		n *= -1;
	else
	{
		buffer[*bufpos] = '-';
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		sign_print = 1;
	}
	if ((n / 10) != 0)
	{
		chars = print_number(((n / 10) * -1), buffer, buflen, bufpos);
	}
	buffer[*bufpos] = (n % 10) * -1 + '0';
	*bufpos += 1;
	buflen += 1;
	if (*buflen == 1024)
		write_buffer(buffer, buflen, bufpos);
	if (sign_print > 0)
		chars += sign_print;
	chars++;
	return (chars);
}
