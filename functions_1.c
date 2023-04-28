#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFFER_SIZE - 2;
	unsigned long int u = va_arg(args, unsigned long int);

	u = convert_size_unsign(u, size);

	if (u == 0)
		buffer[k--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	while (u > 0)
	{
		buffer[k--] = (u % 10) + '0';
		u /= 10;
	}
	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFFER_SIZE - 2;
	unsigned long int u = va_arg(args, unsigned long int);
	unsigned long int init_u = u;

	UNUSED(width);

	u = convert_size_unsign(u, size);

	if (u == 0)
		buffer[k--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (u > 0)
	{
		buffer[k--] = (u % 8) + '0';
		u /= 8;
	}
	if (flags & F_HASH && init_u != 0)
		buffer[k--] = '0';
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexad(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexad_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexad_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexad(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexad - Prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexad(va_list args, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFFER_SIZE - 2;
	unsigned long int u = va_arg(args, unsigned long int);
	unsigned long int init_u = u;

	UNUSED(width);

	u = convert_size_unsign(u, size);

	if (u == 0)
		buffer[k--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (u > 0)
	{
		buffer[k--] = map_to[u % 16];
		u /= 16;
	}
	if (flags & F_HASH && init_u != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}
	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
