#include "main.h"
/**
 * print_binary - convert unsigned int to binary
 * @n: integer
 */
void print_binary(unsigned int n)
{
	int b;

	if (n > 0)
	{
		b = n % 2;
		print_binary(n /= 2);
		_putchar(b + 48);
	}
}
