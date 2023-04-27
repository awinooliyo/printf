#include "main.h"


/**
* _sprintf - prints an argument based on the type.
* @fmt: the formatted string in which to print the arguments.
* @list: list of arguments to print.
* @index: index.
* @buffer: buffer array to handle the print.
* @flags: calculates the active flags.
* @width: gets the width.
* @precision: the precision specification.
* @size: the size specifier.
* Return: either 1 or 2;
*/

int _sprintf(const char *fmt, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int y, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'%', print_percent}, {'s', print_string},
		{'i', print_int}, {'b', print_binary}, {'d', print_int},
		{'u', print_unsigned}, {'R', print_rot13string}, {'S', print_non_printable},
		{'p', print_pointer}, {'X', print_hexa_upper},
		{'x', print_hexadecimal}, {'o', print_octal}, {'\0', NULL}
	};
	for (y = 0; fmt_types[y] != '\0'; y++)
		if (fmt[*index] == fmt_types[y].fmt)
			return (fmt_types[y].fn(list, buffer, flags, width, precision, size));
	if (fmt_types[y].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%'
			--(index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &fmt[index], 1);
		return (unknow_len);
	}
	return (printed_chars);

}
