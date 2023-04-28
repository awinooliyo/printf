#include "main.h"

/**
* is_printable - evaluates whether a char is printable or not.
* @b: char to be evaluated.
* Return: 1 if str is printable and 0 if it is not.
*/

int is_printable(char b)
{
	if (b >= 32 && b < 127)
		return (1);
	return (0);
}

/**
* append_hexa_code - Append Ascii in hexadecimal code to buffer.
* @buffer: an array of characters.
* @k: index where to start appending.
* @ascii_code: ASCII CODE.
* Return: always 3.
*/

int append_hexa_code(char ascii_code, char buffer[], int k)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[k++] = '\\';
	buffer[k] = 'x';

	buffer[k++] = map_to[ascii_code / 16];
	buffer[k++] = map_to[ascii_code % 16];

	return (3);
}

/**
* is_digit - checks whether a char is digit or not.
* @x: char to evaluate.
* Return: 1 if char is digit, and 0 if it is not.
*/

int is_digit(char x)
{
	if (x >= '0' && x <= '9')
		return (1);

	return (0);
}

/**
* convert_size_unsign - casts number to the specified size.
* @num: number to cast.
* @size: number indicating the type being cast.
* Return: casted value of num.
*/

long int convert_size_unsign(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
* convert_size_num - casts number to the specified size.
* @num: number to cast.
* @size: number indicating the type being cast.
* Return: casted value of num.
*/
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
