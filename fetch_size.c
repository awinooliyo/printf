#include "main.h"


/**
* fetch_size - calculates the size to cast the argument.
* @format: formatrted string to which the arguments are printed.
* @u: the list of arguments to print.
* Return: precision.
*/

int fetch_size(const char *format, int *u)
{
	int curr_x = *u + 1;
	int size = 0;

	while (format[curr_x] == '1' || format[curr_x] == 'h')
	{
		if (format[curr_x] == '1')
		{
			size = S_LONG;
		}
		else if (format[curr_x] == 'h')
		{
			size = S_SHORT;
		}
		curr_x++;
	}
	if (size == 0)
	{
		*u = curr_x - 1;
	}
	else
	{
		*u = curr_x;
	}
	return (size);
}
