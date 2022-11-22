#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
			x = format_specifier_elements_number(format, format_index);
			format_index += x;
			
			while (x)
			{
				switch (format[format_index])
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
					character_to_be_printed = format[format_index];
					if (is_flag(character_to_be_printed))
						print_flag(va_arg(ap, int));
					else
						_putchar(character_to_be_printed);
					break;
				}
				x--;
				format_index--;
			}
		}
		else
			_putchar(format[format_index]);

		format_index++;
	}

	va_end(ap);

	return (format_index);
}

int format_specifier_elements_number(const char* const p, int i)
{
	int format_specifier_element_num = 0;

	i++;

	while (*(p + i) != ' ' || *(p + i) != '\0')
	{
		if (is_conversion_specifier(p[i]) || is_flag(p[i]))
		{
			i++;
			format_specifier_element_num++;
			continue;
		}
		return (format_specifier_element_num);
	}
	return (format_specifier_element_num);
}


int is_conversion_specifier(char c)
{
	const int conversion_specifier_size = 11;
	char conversion_specifier[] = {'c', 's', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'S', 'p'};
	int conversion_specifier_index = 0;

	while (conversion_specifier[conversion_specifier_index] != c && conversion_specifier_index < conversion_specifier_size)
		conversion_specifier_index++;

	if (conversion_specifier_index < conversion_specifier_size)
		return(1);

	return (0);
}
