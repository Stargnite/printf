#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct call - struct call
 * @t: flag for data type
 * @f: function - associated function
 */

typedef struct call
{
	char t;
	int (*f)(char *, va_list, int);
} call_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list ar_list);
int (*get_func(char s))(va_list ar_lsit);
int print_s(va_list ar_list);
int print_d(va_list ar_list);
int print_i(va_list ar_list);
int print_b(va_list ar_list);
int print_u(va_list ar_list);
int print_o(va_list ar_list);
int print_x(va_list ar_list);
int print_X(va_list ar_list);

#endif
