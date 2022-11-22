#include <unistd.h>

/**
* _putchar - prints a character on screen
* @c: character  to be printed on screen
*
* Return: a numberical value iindicating the status of execution of the program
*/

int _putchar(char c)
{
	static char buf[1024];

	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
    	return (1);
}
