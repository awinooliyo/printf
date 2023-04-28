#include "main.h"

/************************* PRINT CHAR *************************/
/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(args, int);

	return (handle_write_char(b, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int strlength = 0, k;
	char *strng = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strng == NULL)
	{
		strng = "(null)";
		if (precision >= 6)
			strng = "      ";
	}
	while (strng[strlength] != '\0')
		strlength++;
	if (precision >= 0 && precision < strlength)
		strlength = precision;
	if (width > strlength)
	{
		if (flags & F_MINUS)
		{
			write(1, &strng[0], strlength);
			for (k = width - strlength; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - strlength; k > 0; k--)
				write(1, " ", 1);
			write(1, &strng[0], strlength);
			return (width);
		}
	}
	return (write(1, strng, strlength));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/************************* PRINT INT *************************/
/**
 * print_int - Print an int
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(args, long int);
	unsigned long int u;

	m = convert_size_num(m, size);

	if (m == 0)
		buffer[k--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	u = (unsigned long int)m;
	if (m < 0)
	{
		u = (unsigned long int)((-1) * m);
		is_negative = 1;
	}
	while (u > 0)
	{
		buffer[k--] = (u % 10) + '0';
		u /= 10;
	}
	k++;
	return (write_number(is_negative, k, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of character printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, j, k, sum;
	unsigned int z[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(args, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	z[0] = m / j;
	for (k = 1; k < 32; k++)
	{
		j /= 2;
		z[k] = (m / j) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += z[k];
		if (sum || k == 31)
		{
			char v = '0' + z[k];

			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
