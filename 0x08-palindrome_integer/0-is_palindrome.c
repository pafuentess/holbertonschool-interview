#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - difine is a number is palindrome
 * @n: nunmber to evaluate
 * Return: 1 palindrome 0 no palindrome
 */

int is_palindrome(unsigned long n)
{
	unsigned long copy, alreves, aux;

	alreves = 0;
	copy = n;
	aux = 0;

	while (n != 0)
	{
		aux = n % 10;
		alreves = alreves * 10 + aux;
		n = n / 10;
	}
	if (copy == alreves)
		return (1);
	return (0);
}
