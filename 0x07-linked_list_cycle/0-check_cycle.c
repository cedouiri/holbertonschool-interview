#include "lists.h"
/**
* check_cycle - a function in C that checks if a singly
*linked list has a cycle in it
*
*
* @list: a pointer that point to the head
* Return: 0 if there is no cycle, 1 if there is a cycle
**/

int check_cycle(listint_t *list)
{
	listint_t *j = list;
	listint_t *i = list;

	if (list)
	{
		while (i->next)
		{
			i = i->next;
			if (!i->next)
				return (0);
			i = i->next;
			j = j->next;
			if (i == j)
				return (1);
		}
	}
	return (0);
}
