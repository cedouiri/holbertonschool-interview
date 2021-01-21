#include "lists.h"

/**
* is_palindrome - a function in C that checks if a
*singly linked list is a palindrome
* @head: double pointer to the head
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
**/

int is_palindrome(listint_t **head)
{
	int i = 0, j = 0, k;
	listint_t *begin, *end;

	if (!head)
		return (0);
	if (!(*head))
		return (1);
	end = *head;
	begin = *head;
	i += 1;
	while (end->next)
	{
		end = end->next;
		i++;
	}
	k = i / 2;
	while (j <= k)
	{
		if (begin->n != end->n)
			return (0);
		begin += 2;
		end -= 2;
		j++;
	}
	return (1);
}
