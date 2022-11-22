#include "main.h"

void print_base(int base, int num)
{
	int r;

	if (num < base)
		_putchar(48 + num);
	else
	{
		r = num % base;
		print_base(base, num / base);
		_putchar(48 + r);
	}
}
