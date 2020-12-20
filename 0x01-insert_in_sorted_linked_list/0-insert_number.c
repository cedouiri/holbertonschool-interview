#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted
 *singly linked list
 * @head: pointer to a pointer that point to a head of list
 * @number: the number to add
 * Return: the address of the new node, or NULL if it failed
 **/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *i;

	if (!head)
	return (NULL);
	i = *head;

	node = malloc(sizeof(listint_t));
	if (!node)
	return (NULL);
	node->n = number;
	node->next = NULL;

	if (!*head)
	{
		*head = node;
		return (node);
	}

	if (i->n > number)
	{
		*head = node;
		node->next = i;
		return (node);
	}

	while (i->next && i->next->n < number)
	i = i->next;
	node->next = i->next;
	i->next = node;
	return (node);
}
