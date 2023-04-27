#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_b = 0, pad = ' ';
	int index = BUFFER_SIZE - 2, strlength = 2, pad_start = 1; /* strlength=2, for '0x' */
	unsigned long u_adrs;
	char map_to[] = "0123456789abcdef";
	void *adrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	u_adrs = (unsigned long)adrs;

	while (u_adrs > 0)
	{
		buffer[index--] = map_to[u_adrs % 16];
		u_adrs /= 16;
		strlength++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		extra_b = '+', strlength++;
	else if (flags & F_SPACE)
		extra_b = ' ', strlength++;
	index++;
	/*return (write(1, &buffer[i], BUFFER_SIZE - k - 1));*/
	return (write_pointer(buffer, index, strlength,
		width, flags, pad, extra_b, pad_start));
}
/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, offset = 0;
	char *strng = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strng == NULL)
		return (write(1, "(null)", 6));
	while (str[k] != '\0')
	{
		if (is_printable(strng[k]))
			buffer[k + offset] = str[k];
		else
			offset += append_hexa_code(strng[k], buffer, k + offset);
		k++;
	}
	buffer[k + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *strng;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	strng = va_arg(args, char *);

	if (strng == NULL)
	{
		UNUSED(precision);
		strng = ")Null(";
	}
	for (k = 0; strng[k]; k++)
		;
	for (k = k - 1; k >= 0; k--)
	{
		char v = strng[k];

		write(1, &v, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char s;
	char *strng;
	unsigned int k, t;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strng = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; strng[k]; k++)
	{
		for (t = 0; in[t]; t++)
		{
			if (in[t] == strng[k])
			{
				s = out[t];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[t])
		{
			s = strng[k];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
