#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - displays on screen a formatted text input to the function
 * @format - the formatted text to be displayed
 * Return: the number of characters printed on screen
 */

int _printf(const char * const format, ...)
{
	int format_index = 0;
	int x;
	va_list ap;

	va_start(ap, format);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%') 
		{
			x = format_specifier_elements_number(format, format_index);
			format_index += 1;

			if (get_conversion_type(format[format_index - 1 + x]) == -1)
				print_as_it_is(format, &format_index, x);
			else if (get_conversion_type(format[format_index - 1 + x]) < 9)
				print_char_int(format, &format_index,va_arg(ap, int), x);
			else if (get_conversion_type(format[format_index - 1 + x]) < 11)
				print_strin(format, &format_index, va_arg(ap, char *), x);
		}
		else
			_putchar(format[format_index]);
		format_index++;
	}
	va_end(ap);
	return (format_index);
}

void print_char_int(const char * const p, int *i, int n, int x)
{
	while (x)
	{
		switch (p[*i])
		{
		case 'c':
			_putchar(n);
			break;
		case 'd':
		
		case 'i':
			print_number(n);
			break;
		case 'b':
                	print_base(2, n);
                	break;
		case 'u':
			print_number(n);
			break;
		case 'o':
			print_base(8, n);
			break;
		case 'x':
			print_hex(n, p[*i]);
			break;
		case 'X':
			print_hex(n, p[*i]);
			break;
		case 'p':
			print_pointer(n);
			break;
		default:
	  		if (is_flag(p[*i]))
				print_flag(n, p[(*i) - 1 + x]);
          		else
                		_putchar(p[*i]);
			break;
		}
		(*i) += 1;
		x--;
	}
	(*i) -= 1;
}

void print_strin(const char * const p, int *i, char *s_s, int x)
{

	while (x)
	{
		switch (p[*i])
		{
		case 's':
			print_string(s_s);
			break;
		case 'S':
			print_str(s_s);
			break;
		default:
			/*if (is_flag(p[*i]))
				print_flag(n, p[*i]);
			else*/
			_putchar(p[*i]);
			break;
		}
		(*i) += 1;
		x--;
	}
	(*i) -= 1;
}

void print_as_it_is(const char * const p, int *i, int x)
{
	while (x)
	{
		_putchar(p[*i]);
		(*i) += 1;
		x--;
	}
}
