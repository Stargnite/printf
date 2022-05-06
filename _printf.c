#include "main.h"

/**
 * _printf - output formatted string to stdout
 * @format: input string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	char current_char;

	va_list arg;

	if (format == 0)
		return (-1);
	va_start(arg, format);
	current_char = *format;
	while (current_char != '\0')
	{
		format++;
		if (current_char != '%')
		{
			_putchar(current_char);
			continue;
		}
		switch (*format++)
		{
			case '%':
				_putchar('%');
				break;
			case 'o':
				my_putoct(va_arg(arg, unsigned int));
				break;
			case 'u':
				my_unsigned_int(va_arg(arg, unsigned int));
				break;
			case 'x':
				my_put_unsigned_int_hex(va_arg(arg, unsigned int), 1);
				break;
			case 'X':
				my_put_unsigned_int_hex(va_arg(arg, unsigned int), 0);
				break;
			case 's':
				my_putstr(va_arg(arg, char *));
				break;
			case 'c':
				_putchar(va_arg(arg, int));
				break;
			case 'i':
			case 'd':
				my_putint(va_arg(arg, int));
				break;
		}
	}
	va_end(arg);
	return (0);
}
