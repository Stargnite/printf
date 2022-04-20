#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct char_funcs - struct to find function based on char
 * @c: char to check as key
 * @f: pointer to function call
 */
typedef struct char_funcs
{
	char *indentifier;
	int (*printer)(va_list);
} struct_identifier;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list arg);
int print_int(va_list arg);
int print_s(va_list arg);
int print_mod(void);
int print_unsignedIntToHex(unsigned int num, char _case);

#endif
