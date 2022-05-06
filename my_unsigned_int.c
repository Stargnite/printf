#include "main.h"

void my_unsigned_int(unsigned int n)
{
	if (n >= 10)
	{
		my_unsigned_int(n / 10);
		my_unsigned_int(n % 10);
	}
	else
		_putchar(48 + n);
}
