#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - displays on screen a formatted text inout to thr function
 * @format - the text to be displayed
 * Return: the number of characters printeed on screen
 */

int _printf(const char * const format, ...)
{
	int format_index = 0;
	int x, character_to_be_printed;
	char *specifier_substitute;
	va_list ap;

	va_start(ap, format);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%') 
		{
			x = format_specifier_elements_number(format, format_index++);
			
			while (x)
			{
				switch (format[format_index + 1])
				{
				case 'p':
					character_to_be_printed = va_arg(ap, int);
					print_pointer(character_to_be_printed);
					break;
				case 'S':
					specifier_substitute = va_arg(ap, char*);
					print_str(specifier_substitute);
					break;
				case 'X':
					character_to_be_printed = va_arg(ap, int);
					print_hex(character_to_be_printed, 'X');
					break;
				case 'x':
					character_to_be_printed = va_arg(ap, int);
					print_hex(character_to_be_printed, 'x');
					break;
				case 'o':
					character_to_be_printed = va_arg(ap, int);
					print_base(8, character_to_be_printed);
					break;
				case 'u':
					character_to_be_printed = va_arg(ap, int);
					print_number(character_to_be_printed);
					break;
				case 'b':
					character_to_be_printed = va_arg(ap, int);
					print_base(2, character_to_be_printed);
					break;
				case 'i':

				case 'd':
					character_to_be_printed = va_arg(ap, int);
					print_number(character_to_be_printed);
					break;
				case 's':
					specifier_substitute = va_arg(ap, char *);
					print_string(specifier_substitute);
					break;
				case 'c':
					character_to_be_printed = va_arg(ap, int);
					_putchar(character_to_be_printed);
					break;
				default:
					if (is_flag(format[format_index]))
						print_flag(va_arg(ap, int), format[format_index + x]);
					else
						_putchar(format[format_index]);
					break;
				}
				format_index++;
				x--;
			}
		}
		else
			_putchar(format[format_index]);

		format_index++;
	}

	va_end(ap);

	return (format_index);
}
