#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_c - writes character to stdout
 * @arg: the argument
 * Return: 0
 */
int print_c(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_str - prints upper case strings
 * @arg: argument
 * Return: number of characters printed
 */

int print_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');
			print_unsignedIntToHex(str[i], 'A');
		}
		else
			_putchar(str[i]);
	}
	return (i);
}

/**
 * print_s - prints a string with lower case specifier
 * @arg: arguments
 *
 * Return: number of characters printed
 */

int print_s(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_int - prints an integer
 * @arg: argument
 *
 * Return: 0
 */

int print_int(va_list arg)
{
	unsigned int divisor = 1, i, resp, charPrinted = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		charPrinted++;
		n *= -1;
	}
	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;
	for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (charPrinted);
}
