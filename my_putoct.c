#include "main.h"

void my_putoct(unsigned int n)
{
	int res, i;

	res = 0;
	i = 1;
	while (n != 0)
	{
		res += (n % 8) * i;
		n = n / 8;
		i = i * 10;
	}
	_putchar(res);
}
