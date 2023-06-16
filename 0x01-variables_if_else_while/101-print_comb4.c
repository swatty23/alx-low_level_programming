#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * mai - Entry point 
 * Return: Always 0 (Success)
 */

int main(void)
{
	void printCombination(int a, int b, int c) {
	putchar('0' + a);
        putchar('0' + b);
        putchar('0' + c);
        putchar(',');
        putchar(' ');
	}

	void printAllCombinations() {
        for (int i = 0; i <= 7; i++) {
        for (int j = i + 1; j <= 8; j++) {
        for (int k = j + 1; k <= 9; k++) {
        printCombination(i, j, k);
	}
	}
	}
	}
	return (0);
}
