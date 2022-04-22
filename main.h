#ifndef _MAIN_H_
#define _MAIN_H_
#define INT_BITS (4 * 8)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct call - struct call
 * @t: t - flag for data type
 * @f: function - associated function
 */

typedef struct call
{
	char t;
	int (*f)(char *, va_list, int);
} call_t;

int _print(const char *format, ...);
int buff_append(char *buff_dest, va_list arg, int buff_count, char type);
int print_buff(char *buff, unsigned int nbuff);
int str_len(char *s);
char *_strcpy(char *dest, char *src);
int parse_char(char *buff_dest, va_list arg, int buff_count);
int parse_string(char *buff_dest, va_list arg, int buff_count);
int parse_int(char *buff_dest, va_list arg, int buff_count);
int parse_mod(char *buff_dest, va_list arg, int buff_count);
int parse_binary(char *buff_dest, va_list arg, int buff_count);
int parse_oct(char *buff_dest, va_list arg, int buff_count);
int parse_hex(char *buff_dest, va_list arg, int buff_count);
int parse_uint(char *buff_dest, va_list arg, int buff_count);
int parse_rev(char *buff_dest, va_list arg, int buff_count);
int parse_X(char *buff_dest, va_list arg, int buff_count);
int parse_R13(char *buff_dest, va_list arg, int buff_count);

#endif
