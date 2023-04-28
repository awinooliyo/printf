#include "main.h"

/**
* _sprintf - prints an argument based on the type.
* @format: the formattedtring in which to print the arguments.
* @list: list of arguments to print.
* @index: index.
* @buffer: buffer array to handle the print.
* @flags: calculates the active flags.
* @width: gets the width.
* @precision: the precisionpecification.
* @size: theizepecifier.
* Return: either 1 or 2;
*/

int _sprintf(const char *format, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int y, unknow_len = 0, printed_chars = -1;
	n_format format_types[] = {
		{'c', print_char}, {'%', print_percent}, {'s', print_string},
		{'i', print_int}, {'b', print_binary}, {'d', print_int},
		{'u', print_unsigned}, {'R', print_rot13string}, {'S', print_non_printable},
		{'p', print_pointer}, {'X', print_hexa_upper},
		{'x', print_hexadecimal}, {'o', print_octal}, {'\0', NULL}
	};
	for (y = 0; format_types[y]._format != '\0'; y++)
		if (format[*index] == format_types[y]._format)
			return (format_types[y].myfunc(list, buffer,
				flags, width, precision, size));
	if (format_types[y]._format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
			--(index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &format[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);

}
