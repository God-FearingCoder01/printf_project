#include "main.h"


char flags[] = {'+', ' ', '#'};
const int flags_size = 3;
static int flags_index;

int is_flag(char k)
{
	flags_index = 0;

	while (k != flags[flags_index] && flags_index < flags_size)
		flags_index++;
	if (flags_index  < flags_size)
		return (1);
	return (0);
}

void print_flag(int n)
{

	switch (flags_index)
	{
	case 0:
		check_positivity(n, flags[flags_index]);
		break;
	case 1:
		check_positivity(n, flags[flags_index]);
		break;
	case 2:
		break;
	}
}

void check_positivity(int m, char c)
{
	if (m + absolute(m))
	{
		_putchar(c);
		print_number(m);
	}
	else
		print_number(m);
}
