#include "main.h"

/**
 * p_c - prints a character.
 * @args: list of arguments.
 * Return: 0 Success.
 */
int p_c(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * p_s - prints a string.
 * @args: list of arguments.
 * Return: The number of characters in a string.
 */
int p_s(va_list args)
{
	int i = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * per_cent - prints a percentage.
 * @args: list of arguments.
 * Return: 0 Success.
 */
int per_cent(va_list args __attribute__((unused)))
{
	_putchar('%');
	return (1);
}
