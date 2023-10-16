#include "main.h"

/**
 * get_conv - chooses which conversion function to use
 * according to the formatmt
 * @fmt: character string
 * @list: list of arguments
 * Return: number of charachters printed
 */
int get_conv(const char fmt, va_list list)
{
	int total = 0;

	if (fmt != NULL)
	{
		switch (fmt)
		{
		case 'c':
			total = print_chr((char)va_arg(list, int));
			break;
		case 's':
			total = print_str(va_arg(list, char *));
			break;
		case '%':
			total += print_chr(fmt);
			break;
		case 'd':
		case 'i':
			total += print_bin((long)va_arg(list, int));
			break;
		case 'b':
			total += print_bin(va_arg(list, unsigned int));
			break;
		default:
			total += print_chr('%');
			total += print_chr(fmt);
			break;
		}
	}
return (total);
}

/**
 * print_chr - prints a single character to
 * standard output using write
 * @fmt: character to print
 * Return: total no. of char printed to stdo
 */

int print_chr(int fmt)
{
	return (write(1, &fmt, 1));
}

/**
 * print_dec - prints an integer recursively
 * @num: integer to print
 * Return: integer
 */
int print_dec(long int num)
{
	int total;

	if (num < 0)
	{
		print_chr('-');
		num = -num;
	}
	else if (num > 9)
	{
		total = print_dec(num / 10);
		return ((total + print_dec(num % 10)));
	}
	else
	{
		return (print_chr(num + '0'));
	}

	return (0);
}

/**
 * print_str - prints a string to standard output
 * using write function
 * @fmt: format string to be printed
 * Return: total no. of characters printed
 */

int print_str(char *fmt)
{
	int total = 0;

	fmt = (fmt == NULL) ? "(null)" : fmt;

	while (*fmt != '\0')
	{
	total += print_chr(*fmt);
	++fmt;
	}
	return (total);
}

/**
 * print_bin - recursively prints number in binary
 * @n: number to print
 * Return: no. of characters printed
 */

int print_bin(unsigned int n)
{
	int binary;
	int total = 0;

	if (n == 0)
	{
		print_chr('0');
		return (1);
	}

	while (n >= 1)
	{
		total = print_bin(n / 2);
	}

	binary = (total + print_chr(n % 2) + '0');
	return (binary);
}
