#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int get_digits(int n);

int _printf(const char * const format, ...)
{
	int index = 0;
	int my_index, num_digits;
	int ch;
	char my_array[] = {'c', 'i', 's'};
	char *c_v;
	va_list ap;

	va_start(ap, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			my_index = 0;
			while (format[index] != my_array[my_index] && my_index < 3)
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
			/*output_string[index] = (char)ch;*/
		}
		else
		{
			/*output_string[index] = format[index];*/
			_putchar(format[index]);
		}
		index++;
	}

	/*output_string[index] = '\0';*/
	va_end(ap);

	/*for (i = 0; output_string[i] != '\0'; i++)
		write(1, &output_string[i], 1);	*/

	return (index);
}

int get_digits(int n)
{
	int digits = 0;
	const int base = 10;

	while (n > 0)
	{
		digits++;
		n /= base;
	}

	return (digits);
}