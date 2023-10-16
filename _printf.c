#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * @...: shows function is variadic
 * Return: int, number of characters printed
 */

int _printf(const char *format, ...)
{
	int total = 0;
	va_list list;


	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != NULL)
			total += get_conv(format, list);
		else
		{
			total += print_chr(*format);
		}
		++format;
	}
	va_end(list);
	return (total);
}
