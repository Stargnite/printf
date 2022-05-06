#include "main.h"

void my_putint(int n)
{
	if (n == -2147483648)
		my_putstr("-2147483648");
	if ( n >= 10)
	{
		my_putint(n / 10);
		my_putint(n % 10);
	}
	else
		_putchar(48 + n);
}
