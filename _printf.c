#include "main.h"

/**
 * _printf - output formatted string to stdout
 * @format: input string
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;
	char buffer[2000];
	va_list arg;
	call_t container[] = {
		{'c', parse_char}, {'X', parse_X}, {'R', parse_R13},
		{'s', parse_string}, {'i', parse_int}, {'d', parse_int},
		{'%', parse_mod}, {'b', parse_binary}, {'o', parse_oct},
		{'x', parse_hex}, {'r', parse_rev}, {'u', parse_uint}, {'\0', NULL}
	};
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++, prev_buff_count = buff_count;
			for (j = 0; container[j].t != '\0'; j++)
			{
				if (format[i] == '\0')
					break;
				if (format[i] == container[j].t)
				{
					buff_count = container[j].f(buffer, arg, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[i])
				i--, buffer[buff_count] = format[i], buff_count++;
		}
		else
			buffer[buff_count] = format[i], buff_count++;
		i++;
	}
	va_end(arg);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
}
