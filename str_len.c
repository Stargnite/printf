#include "main.h"

/**
 * str_len - returns length of a string
 * @s: string param
 * Return: 0
 */

int str_len(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}
