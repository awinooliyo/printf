#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: character string
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int k, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_index++] = format[k];
			if (buff_index == BUFFER_SIZE)
				print_buffer(buffer, &buff_index);
			/*
			* write(1, &format[k], 1);
			* The function in this comment is to print
			*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = fetch_flags(format, &k);
			width = fetch_width(format, &k, list);
			precision = fetch_precision(format, &k, list);
			size = fetch_size(format, &k);
			++k;
			printed = _sprintf(format, &k, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
