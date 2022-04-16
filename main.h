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
	char *c;
	int (*f)();
} char_funcs_t;

void write_buffer(char buffer[], int *buflen, int *bufpos);
void initialize_buffer(char buffer[]);
int _printf(const char *format, ...);
int print_c(va_list args, char buffer[], int *buflen, int *bufpos);
int print_int(va_list args, char buffer[], int *buflen, int *bufpos);
int print_s(va_list args, char buffer[], int *buflen, int *bufpos);
int print_number(int n, char buffer[], int *buflen, int *bufpos);

#endif
