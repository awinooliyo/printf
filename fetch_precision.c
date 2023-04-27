#include "main.h"

/**
* fetch_precision - calculates the precision for printing.
* @format: formatted string in which to print the arguments.
* @u: list of arguments to be printed.
* @list: the list of arguments.
* Return: precision.
*/

int fetch_precision(const char *format, int *u, va_list list)
{
	int curr_y = *u + 1;
	int precision = -1;

	if format[curr_y] != '.')
		return (precision);

	precision = 0;

	for (curr_y += 1; format[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(format[curr_y]))
		{
			precision *= 10;
			precision += formart[curr_y] - '0';
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*u = curr_y - 1;

	return (precision);
}
