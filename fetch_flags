#include <main.h>

/**
* fetch_flags - calculates the active flags.
* @format: formatted string to print the arguments to.
* @k: take a parameter.
*
* Return: Flags.
*/

int fetch_flags(const char *format, int *k)
{
	int x, curr_y;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_y = *k + 1; format[curr_y] != '\0'; curr_y++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[curr_y] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x]
				break;
			}
		if (FLAGS_CH[x] == 0)
			break;
	}
	*k = curr_y - 1;

	return (flags);
