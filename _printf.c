#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char * const format, ...)
{
	int format_index = 0;
	int conversion_specifier_index, character_to_be_printed;
	char conversion_specifier[] = {'c', 's', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'S', 'p'};
	char *specifier_substitute;
	va_list ap;

	va_start(ap, format);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%') 
		{
			format_index++;	
			conversion_specifier_index = 0;	
			while (format[format_index] != conversion_specifier[conversion_specifier_index] && conversion_specifier_index < 11)
				conversion_specifier_index = conversion_specifier_index + 1;	
			
			switch (conversion_specifier_index)
			{
			case 11:
				character_to_be_printed = format[format_index];
				_putchar(character_to_be_printed);
				break;
			case 10:
				character_to_be_printed = va_arg(ap, int);
				print_pointer(character_to_be_printed);
				break;
			case 9:
				specifier_substitute = va_arg(ap, char*);
				print_str(specifier_substitute);
				break;
			case 8:
				character_to_be_printed = va_arg(ap, int);
				print_hex(character_to_be_printed, 'X');
				break;
			case 7:
				character_to_be_printed = va_arg(ap, int);
				print_hex(character_to_be_printed, 'x');
				break;
			case 6:
				character_to_be_printed = va_arg(ap, int);
				print_base(8, character_to_be_printed);
				break;
			case 5:
				character_to_be_printed = va_arg(ap, int);
				print_number(character_to_be_printed);
				break;
			case 4:
				character_to_be_printed = va_arg(ap, int);
				print_base(2, character_to_be_printed);
				break;
			case 3:
				
			case 2:
				character_to_be_printed = va_arg(ap, int);
				print_number(character_to_be_printed);
				break;
			case 1:
				specifier_substitute = va_arg(ap, char *);
				print_string(specifier_substitute);
				break;
			case 0:
				character_to_be_printed = va_arg(ap, int);
				_putchar(character_to_be_printed);
				break;
			}
		}
		else
			_putchar(format[format_index]);

		format_index++;
	}

	va_end(ap);

	return (format_index);
}
