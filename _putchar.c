#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 0 on success, -1 on failure
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
