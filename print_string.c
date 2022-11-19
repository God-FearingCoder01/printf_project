#include "main.h"

void print_string(char *str)
{
	int str_index = 0;

	while (*(str + str_index) != 0)
	{
		_putchar(str[str_index]);
		str_index++;
	}
}
