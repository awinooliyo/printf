#include "main.h"

/**
* fetch_width - calculates the width for printing.
* @format: the formated string where to print the arguments.
* @u: the list of arguments being printed.
* @list: the list of all arguments.
* Return: width.
*/

int fetch_width(const char *format, int *u, va_list list)
{
	int curr_x;
	int width = 0;

	while (format[curr_x] != '\0')
	{
		if (is_digit(format[curr_x]))
		{
			width *= 10;
			width += format[curr_x] - '0';
			curr_x++;
		}
		else if (format[curr_x] == '*')
		{
			curr_x++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*u = curr_x - 1;
	return (width);
}
