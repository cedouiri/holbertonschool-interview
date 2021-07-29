#include "holberton.h"

/**
 * slen - the length of a string
 * @s: string
 * @n: the index
 *
 *
 * Return: the number of characters in a string.
 */
int slen(char *s, int n)
{
	if (s[n] == '\0')
	{
		return (n);
	}
	return (slen(s, n + 1));
}

/**
 * cmp_char - Compares 2 strings
 * @s1: first string
 * @s2: second string
 * @i: index 1.
 * @j: index 2.
 *
 *
 * Return: 1 if the 2 strings' characters are identical, otherwise returns 0.
 */
int cmp_char(char *s1, char *s2, int i, int j)
{
	int r = 0;

	if (!s1[i] && !s2[j])
		r = 1;
	else if (s2[j] != '*' && s1[i] != s2[j])
		r = 0;
	else if (s1[i] == s2[j])
		r = cmp_char(s1, s2, ++i, ++j);
	else if (s2[j] == '*')
	{
		if (!s2[j + 1])
			r = 1;
		else if (s2[j + 1] && s2[j + 1] == '*')
			r = cmp_char(s1, s2, i, ++j);
		else if (s2[j + 1] && s2[j + 1] == s1[i])
		{
			if (slen(&(s2[j + 1]), 0) < slen(&(s1[i]), 0))
				r = cmp_char(s1, s2, ++i, j);
			else
				r = cmp_char(s1, s2, i, ++j);
		}
		else if (s1[i + 1] && s2[j + 1])
		{
			if (s1[i + 1] != s2[j + 1])
				r = cmp_char(s1, s2, ++i, j);
			else if (s1[i + 1] == s2[j + 1])
				r = cmp_char(s1, s2, ++i, ++j);
		}
	}
	return (r);
}

/**
 * wildcmp - Ca function that compares two strings and returns 1
 *if the strings can be considered identical, otherwise return 0
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings are identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	int are_equal;

	are_equal = cmp_char(s1, s2, 0, 0);
	return (are_equal);
}
