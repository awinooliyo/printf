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
	int curr_y = *u + 1;
	int width = 0;

	while (format[curr_y] != '\0')
	{
		if (is_digit(format[curr_y]))
		{
			width *= 10;
			width += format[curr_y] - '0';
			curr_y++;
		}
		else if (format[curr_y] == '*')
		{
			curr_y++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*u = curr_y - 1;
	return (width);
}
