#ifndef MAIN_H
#define MAIN_H

/* The Standard C header files */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


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


/* Functions to print format specifiers*/
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list list);
int fetch_precision(const char *format, int *i, va_list list);
int fetch_size(const char *format, int *i);






#endif
