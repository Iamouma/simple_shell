#include "main.h"

/**
 * bn - turns binary to integer.
 * @args: list of arguments.
 * Return: number of integers.
 */
int bn(va_list args)
{
	long int len = 1, count = 0;
	long int i = va_arg(args, int), j = i;
	int n = 0;

	if (i == 0)
	{
		_putchar('0');
		return (1);
	}

	while (j > 0)
	{
		count++;
		j = j >> 1;
	}

	len = len << (count - 1);

	for (; count > 0; count--)
	{
		if (i & len)
		{
			_putchar('1');
			n++;
		}
		else
		{
			_putchar('0');
			n++;
		}
		len = len >> 1;
	}

	return (n);
}
