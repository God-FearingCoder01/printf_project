#include "main.h"

/**
 * print_base - converts an unsigned integer to another number base, and prints it out
 * @n: number to be converted
 * @b: number base to convert to
 */

void print_base(int b, int n)
{
	int r;

	if (n > 0)
	{
		r = n % b;
		print_base(b, (n / b));
		_putchar(48 + r);
	}
}
