#include "main.h"

/**
 * get_func - search and return the correct function
 * @s: array to check
 * Return: a function if written correctly
 *
 */

int (*get_func(char s))(va_list)
{
	call_t ops[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{"b", print_b},
		{NULL, NULL}
	};

	int i;

	for (i = 0; ops[i].c != NULL; i++)
	{
		if (*ops[i].c == s)
			return (ops[i].f);
	}
	return (NULL);
}
