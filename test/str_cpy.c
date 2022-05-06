#include "main.h"

/**
 * _strcpy - copy strings
 * @dest: pointer param
 * @src: source param
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
