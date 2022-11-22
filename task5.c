#include "main.h"

void print_str(char *str)
{
	int str_index = 0;

	while (*(str + str_index) != '\0')
	{
		if (str[str_index] > 0 && str[str_index] < 32 || str[str_index] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar(48);
			print_hex((int)str[str_index], 'X');
		}
		else
			_putchar(str[str_index]);
		str_index++;
	}
}

/*int get_ascii(char* s)
{
	int i;
	static int s_index = 0;

	while (*(s + S_index) != '\0')
	{
		for (i = 32; i <= 127; i++)
		{
			if (s[i] == i)
				return (i);
		}
		s_index++;
	}
}*/
