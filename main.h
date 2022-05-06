#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void _putchar(char c);
void my_putstr(char *s);
void my_putint(int n);
void my_put_unsigned_int_hex(unsigned int n, int shu);
void my_unsigned_int(unsigned int n);
void my_putoct(unsigned int n);
void my_putbin(unsigned int n);
int my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
int _printf(const char *format, ...);

#endif
