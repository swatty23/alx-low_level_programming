#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary format.
 */

void print_binary(unsigned long int n)
{
	int size = sizeof(unsigned long int) * 8;
	int bit = size - 1;
	int flag = 0;

	if (n == 0)
	{
	_putchar('0');
	return;
	}
	while (bit >= 0)
	{
	if ((n >> bit) & 1)
	{
	_putchar('1');
	flag = 1;
	}
	else if (flag)
	_putchar('0');
	bit--;
	}
}
