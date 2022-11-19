#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char * const format, ...)
{
	int index = 0;
	int my_index, num_digits, ch;
	char my_array[] = {'c', 'i', 's'};
	char *c_v;
	va_list ap;

	va_start(ap, format);

	while (format[index] != '\0') 		//iterates through indivisual characters of format
	{
		if (format[index] == '%')	//checks if the currently picked character of format is a percentage sign or not 
		{		//if it a % sign
			index++;	//shit the value of our index of format to the character after the %
			my_index = 0;	//initialise index of a new array to zero
			while (format[index] != my_array[my_index] && my_index < 3)	//checks if the the value of character after % is either 'c', 'i' or 's'
				my_index++;	
			
			switch (my_index)
			{
			case 3:
				ch = format[index];
				_putchar(ch);
				break;
			case 2:
				c_v = va_arg(ap, char *);
				print_string(c_v);
				break;
			case 1:
				ch = va_arg(ap, int);
				print_number(ch);
				break;
			case 0:
				ch = va_arg(ap, int);
				_putchar(ch);
				break;
			}
		}
		else
			_putchar(format[index]);

		index++;
	}

	va_end(ap);

	return (index);
}
