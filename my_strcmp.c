#include "main.h"

int my_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;

	while (str1[i] != 0 || str2[i] != 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i] < 0 ? -1 : 0);
		i += 1;
	}
	return (0);
}
