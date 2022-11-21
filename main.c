#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int len, len2;
	/*unsigned int ui;*/
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Len: [%d]\n", len);
	_printf("Whurrey %c it worked!\n", 'N');
	_printf("String: [%s]\n", "I am a String !");

	pause_program();

	return (0);
}
