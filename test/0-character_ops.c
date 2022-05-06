#include "main.h"

/**
 * print_c - prints character
 * @ar_list: buffer of character
 * Return: num of character printed
 */

int print_c(va_list ar_list)
{
	int c = va_arg(ar_list, int);

	return (_putchar(c));
}

/**
 * print_s - print string
 * @ar_list: buffer param
 * Return: number of characters printed
 */

int print_s(va_list ar_list)
{
	int i, count = 0;
	char *str;

	str = va_arg(ar_list, char *);
	if (str == NULL)
		str = "(NULL)";

	for (i = 0; str[i]; i++)
		count += _putchar(str[i]);

	return (count);
}
