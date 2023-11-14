#include "main.h"
/**
 * df - picks integer value and calls function to print.
 * @args: list of arguments.
 * @Return: length of integer.
 */
int df(va_list args)
{
	long int len = va_arg(args, int);
	long int n;

	n = print_dif(len, 0);

	return (n);
}

/**
 * print_dif - prints signed integers.
 * @len: integer to be printed.
 * @n: length of integer to be printed.
 * Return: length of the integer.
 */
int print_dif(long int len, long int n)
{
	if (len < 0)
	{
		_putchar('-');
		len = -len;
		n++;
	}
	if (len / 10)
	{
		n = print_dif(len / 10, n++);
	}
	_putchar(len % 10 + '0');
	n++;

	return (n);
}

/**
 * dcc - picks integer value and calls function to print.
 * @args: list of arguments.
 * Return: length of integer.
 */
int dcc(va_list args)
{
	long int len = va_arg(args, int);
	long int n;

	n = print_dig_c(len, 0);

	return (n);
}

/**
 * print_dig_c - prints unsigned integers.
 * @len: integer to be printed.
 * @n: lenght of integer.
 * Return: length of integer.
 */
int print_dig_c(long int len, long int n)
{
	if (len < 0)
	{
		len = -len;
		n++;
	}

	if (len / 10)
	{
		n = print_dig_c(len / 10. n++);
	}
	_putchar(len % 10 + '0');
	n++;

	return (n);
}
