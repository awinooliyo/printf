#ifndef MAIN_H
#define MAIN_H

/* The Standard C header files */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) void(x)
/* FLAGS  */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1


/* The Function Prototypes */
int _printf(const char *format, ...);

/* Function helpers */
void print_buffer(char buffer[], int *buff_index);
/**
 * struct _format - Struct op
 *
 * @_format: character variable to store format specifier.
 * @myfunc: a function pointer that points to a function that takes
 *  a variable argument list of type va_list and returns an integer.
 */
struct _format
{
	char _format;
	int (*myfunc)(va_list, char[], int, int, int, int);
};

int _sprintf(const char *_format, int *k,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexad(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size);


/* Function to print characters */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* functions for width*/
int handle_write_char(char b, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_char);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_char, int padd_start);
int write_unsgnd(int is_negative, int index,
char buffer[],
	int flags, int width, int precision, int size);


/**** Functions to print format specifiers *****/
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list list);
int fetch_precision(const char *format, int *i, va_list list);
int fetch_size(const char *format, int *i);


/********Manipulators*******/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsign(unsigned long int, int size);



#endif
