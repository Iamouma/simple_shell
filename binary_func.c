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
