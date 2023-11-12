#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to format.
 * @format: format and character string to be printed.
 * Return: 0 Success.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len, count, num_b = 0;

	prints_d data[] = {
		{"c", p_c}, {"s", p_s}, {"%", per_cent}, {"d", df}, {"i", df}, {"b", bn},
		{"c", dcc}, {"S", p_s}
	};
	va_start(args, format);
	if (!format)
		return (-1);
	for (len = 0; format[len]; len++)
	{
		if (format[len] != '%')
		{
			_putchar(format[len]);
			num_b++;
		}
		else
		{
			if (!format[len + 1] || format[len + 1] == ' ')
				return (-1);
			for (count = 0; count < 8; count++)
			{
				if (format[len + 1] == *(data[count].c))
					break;
			}
			if (count < 8)
			{
				num_b = num_b + data[count].func_p(args);
				len++;
			}
			else
			{
				_putchar(format[len]);
				num_b++;
			}
		}
	}
	va_end(args);
	return (num_b);
}
