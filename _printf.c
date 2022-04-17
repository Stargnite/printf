#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * print_identifier - prints special characters
 * @next: character after mod
 * @arg: argument for the identifier
 * Return: number of characters printed,
 * excluding the null byte
 */

int print_identifier(char next, va_list arg)
{
	int func_index;

	struct_identifier functs[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};

	for (func_index = 0; functs[func_index].indentifier != NULL; func_index++)
	{
		if (functs[func_index].indentifier[0] == next)
			return (functs[func_index].printer(arg));
	}
	return (0);
}

/**
 * _printf - prints from stdin to stdout according to specified format
 * @format: character string of zero or more directives
 * Return: number of character printed,
 * -1 for in complete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int identifier_printed = 0, char_printed = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			char_printed++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar ('%');
			char_printed++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		identifier_printed = print_identifier(format[i + 1], arg);
		if (identifier_printed == -1 || identifier_printed != 0)
			i++;
		if (identifier_printed > 0)
			char_printed += identifier_printed;

		if (identifier_printed == 0)
		{
			_putchar('%');
			char_printed++;
		}
	}
	va_end(arg);
	return (char_printed);
}
