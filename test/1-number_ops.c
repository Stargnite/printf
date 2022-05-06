#include "main.h"

/**
 * print_d - print decimal
 * @ar_list: buffer param
 * Return: counter print numbers
 */

int print_d(va_list ar_list)
{
	unsigned int num_abs, aux_num, count_ze, count;
	int numbers;

	count = 0;

	numbers = va_arg(ar_list, int);

	if (numbers < 0)
	{
		num_abs = (numbers * -1);
		count += _putchar(45);
	}
	else
		num_abs = numbers;
	aux_num = num_abs;
	count_ze = 1;
	while (aux_num > 9)
	{
		aux_num /= 10;
		count_ze *= 10;
	}

	while (count_ze >= 1)
	{
		count += _putchar(((num_abs / count_ze) % 10) + '0');
		count_ze /= 10;
	}
	return (count);
}

/**
 * print_i - print integer
 * @ar_list: buffer param
 * Return: number print
 */

int print_i(va_list ar_list)
{
	return (print_d(ar_list));
}
