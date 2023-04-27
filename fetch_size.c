#include "main.h"


/**
* fetch_size - calculates the size to cast the argument.
* @format: formatrted string to which the arguments are printed.
* @u: the list of arguments to print.
* Return: precision.
*/

int fetch_size(const char *format, int *u)
{
	int curr_y = *u + 1;
	int size = 0;

	while (format[curr_y] == '1' || format[curr_y] == 'h')
	{
		if (format[curr_y] == '1')
		{
			size = S_LONG;
		}
		else if (format[curr_y] == 'h')
		{
			size = S_SHORT;
		}
		curr_y++;
	}
	if (size == 0)
	{
		*u = curr_y - 1;
	}
	else
	{
		*u = curr_y;
	}
	return (size);
}
