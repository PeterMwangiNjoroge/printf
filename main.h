#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*function prototypes*/
int _printf(const char *format, ...);
int get_conv(const char fmt, va_list list);
int print_str(char *fmt);
int print_chr(int fmt);
int print_dec(long int num);
int print_bin(unsigned int n);

#endif
