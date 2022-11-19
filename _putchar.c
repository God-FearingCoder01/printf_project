#include <unistd.h>

/**
* _putchar - prints a character on screen
* @c: character  to be printed on screen
*
* Return: a numberical value iindicating the status of execution of the program
*/

int _putchar(char c)
{
    return (write(1, &c, 1));
}
