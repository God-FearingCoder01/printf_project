#include "main.h"

void print_hex(int num, char v)
{
	int r;
	if (num < 16)
	{
		if (num < 9)
			_putchar(48 + num);
		else
		{
			r = num - 9;
			checks_state(v, r);
		}
	}
	else
	{
		r = num % 16;
		print_hex(num /= 16, v);
		if (r < 9)
			_putchar(48 + r);
		else
			checks_state(v, r);
	}
}

void checks_state(char d, int z)
{
	if (d == 'X')
		_putchar(64 + z);
	else if (d == 'x')
		_putchar(97 + z);
}
