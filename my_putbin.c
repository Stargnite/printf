#include "main.h"

void my_putbin(unsigned int n)
{
	int res, i;

	res = 0;
	i = 1;

	while (n != 0)
	{
		res += (n % 2) * i;
		n = n / 2;
		i = i * 10;
	}
	_putchar(res);
}
