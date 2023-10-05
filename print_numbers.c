#include "main.h"
/**
 * print_numbers - Prints numbers, used to print the error message
 * @n: number to print
 * Return: Number of characters printed
 */
int print_numbers(int n)
{
	unsigned int number;
	int count = 0;

	if (n < 0)
	{
		number = -n;
		count += _putchar('-');
	}
	else
	{
		number = n;
	}

	if (number / 10 != 0)
		count += print_numbers(number / 10);
	count += _putchar(number % 10 + '0');
	return (count);
}
