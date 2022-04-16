#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_c - copy a character into buffer & print if buffer is full
 * @args: va_list of given to _printf
 * @buffer: the buffer being copied to print
 * @buflen: current length of buffer. i.e characters in buffer
 * @bufpos: current position of character. i.e index
 * Return: number of characters copied to buffer
 */
int print_c(va_list args, char buffer[], int *buflen, int *bufpos)
{
	if (*buflen < 1024)
	{
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
	}
	else
	{
		write_buffer(buffer, buflen, bufpos);
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		buflen += 1;
	}
	return (1);
}

/**
 * print_s - copy string into buffer and print if buffer is full
 * @args: va_list of all given arguments to _printf
 * @buffer: the buffer being copied to print
 * @buflen: length of buffer. i.e nums of characters in buffer
 * @bufpos: current position/index of character in buffer
 *
 * Return: number of characters copied to buffer
 */

int print_s(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *str;
	int i, chars;

	i = chars = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		buffer[*bufpos] = str[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		i++;
		chars++;
	}
	return (chars);
}

/**
 * print_int - function to copy a number to the buffer
 * @args: va_list of all given arguments to _printf
 * @buffer: the buffer being copied to
 * @buflen: the current length of the buffer
 * @bufpos: index of characters in the buffer
 *
 * Return: number of characters copied to the buffer
 */

int print_int(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int chars;
	int n;

	n = va_arg(args, int);
	chars = print_number(n, buffer, buflen, bufpos);
	return (chars);
}
