#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * copy_to_buffer - copy character over to the buffer
 * @formatter: character to copy over
 * @buffer: copied characters
 * @buflenptr: pointer to lenght of the buffer.
 * i.e the number of characters in the buffer
 * @bufposptr: pointer to the position of the buffer
 *
 * Return: number of characters copied to buffer
 */

int copy_to_buffer(char formatter, char buffer[], int *buflenptr, int *bufposptr)
{
	int chars;

	chars = 0;
	buffer[*bufposptr] = formatter;
	*bufposptr += 1;
	*buflenptr += 1;
	if (*buflenptr == 1024)
	{
		write_buffer(buffer, buflenptr, bufposptr);
	}
	chars++;
	return (chars);
}

/**
 * check_conversion - checks formatter character to see if
 * it's a conversion specifier
 * @formatter: format character being checked
 * @conversions: struct holding conversion specifiers and
 * function pointers to appropraite functions
 * @buffer: buffer needed to copy-to when calling function
 * @buflenptr: pointer to length of buffer
 * @bufposptr: pointer to position of buffer
 * @print_this: variadic function for all given arguments to _printf
 *
 * Return: the number of characters copied to buffer when
 * function is called, else return 0
 */

int check_conversion(char formatter, char_funcs_t conversions[], char buffer[], int *buflenptr, int *bufposptr, va_list print_this)
{
	int j, chars;

	chars = 0;
	for (j = 0; j < 13; j++)
	{
		if (formatter == *conversions[j].c)
		{
			chars += conversions[j].f(print_this, buffer, buflenptr, bufposptr);
			return (chars);
		}
	}
	return (0);
}

/**
 * formatPrinter - finds the formatters function & prints its argument
 * @format: the character being checked
 * @conversions: struct holding conversion specifiers & function pointer to
 * appropraite functions
 * @buffer: buffer to copy characters to
 * @buflenptr: pointer to length of buffer
 * @bufposptr: pointer to position of buffer
 * @print_this: va_list of arguments for _printf function
 *
 * Return: number of copied characters to buffer, else return 0
 */

int formatPrinter(const char *format, va_list print_this, char buffer[], int *buflenptr, int *bufposptr, char_funcs_t conversions[])
{
	int i, chars, print;

	chars = 0;
	for (i = 0; format[i] != '\0' && format != NULL; i++)
	{
		if (format[i] == '%')
		{
			i++;
			print = check_conversion(format[i], conversions, buffer, buflenptr, bufposptr, print_this);
			if (print == 0)
				chars += copy_to_buffer(format[i], buffer, buflenptr, bufposptr);
			chars += print;
		}
		else
		{
			chars += copy_to_buffer(format[i], buffer, buflenptr, bufposptr);
		}
	}
	return (chars);
}

/**
 * _printf - prints out a formatted string
 * @format: format of string to be pprinted
 * Return: number of charactes printed
 */

int _printf(const char *format, ...)
{
	va_list print_this;
	char buffer[1024];
	int chars, buflen, bufpos, *buflenptr, *bufposptr;
	char_funcs_t conversions[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_int},
		{"i", print_int},
	};

	initialize_buffer(buffer);
	chars = bufpos = 0;
	buflen = 1;
	buflenptr = &buflen;
	bufposptr = &bufpos;
	va_start(print_this, format);

	if (format == NULL || print_this == NULL)
		return (chars);
	chars = formatPrinter(format, print_this, buffer, buflenptr, bufposptr, conversions);
	write_buffer(buffer, buflenptr, bufposptr);
	va_end(print_this);
	return (chars);
}
