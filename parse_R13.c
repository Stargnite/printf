#include "main.h"

/**
 * parse_R13 - sub %R by arg num in R13
 * @buff_dest: string to change
 * @arg: va_list char to change
 * @buff_count: index of dst
 * Return: new index
 */

int parse_R13(char *buff_dest, va_list arg, int buff_count)
{
	char *str;
	char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *newKey = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKKLM";
	int i, j = 0;

	str = va_arg(arg, char*);
	while (str[j])
	{
		for (i = 0; keys[i]; i++)
		{
			if (str[j] == keys[i])
			{
				buff_dest[buff_count] = newKey[i];
				break;
			}
			buff_dest[buff_count] = str[j];
		}
		j++, buff_count++;
	}
	return (buff_count);
}
