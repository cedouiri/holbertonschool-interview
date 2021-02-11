#include "palindrome.h"

/**
* is_palindrome - a function that checks whether or
*not a given unsigned integer is a palindrome
* @n: is the number to be checked
* Return: 1 if n is a palindrome, and 0 otherwise
**/

int is_palindrome(unsigned long n)
{
	unsigned long int i, j;

	if (n == 0)
		return (1);
	i = n % 10;
	j = n;
	while (j / 10 != 0)
	{
		j = j / 10;
		i = i * 10;
	}
	if (j != n % 10)
		return (0);
	n = (n - i) / 10;
	return (is_palindrome(n));
}
