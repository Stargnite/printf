#include "main.h"

void my_put_unsigned_int_hex(unsigned int n, int shu)
{
	int size;

	size = 16;

	if (n >= (unsigned)size - 1)
		my_put_unsigned_int_hex(n / size, 0);
	if (shu == 0)
		_putchar("0123456789ABCDEF"[n % size]);
	else
		_putchar("0123456789abcdef"[n % size]);
}
