#include "list.h"

/**
 * add_node_end - Add a node to the end of a double circular linked list.
 * @list: the list to modify
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *tmp = NULL;
	List *start = NULL;
	List *newNode = NULL;
	char *nodeStr;

	if (!list || *list == NULL)
	{
		tmp = (List *) malloc(sizeof(List));
		if (!tmp)
			return (NULL);
		nodeStr = strdup(str);
		if (!nodeStr)
			return (NULL);
		tmp->str = nodeStr;
		tmp->prev = tmp;
		tmp->next = tmp;
		*list = tmp;
		return (tmp);
	}
	tmp = *list;
	start = *list;
	while (tmp)
	{
		if (tmp->next == NULL || tmp->next == start)
			break;
		tmp = tmp->next;
	}
	newNode = (List *) malloc(sizeof(List));
	if (!newNode)
		return (NULL);
	nodeStr = strdup(str);
	if (!nodeStr)
		return (NULL);
	newNode->str = nodeStr;
	newNode->prev = tmp;
	newNode->next = start;
	tmp->next = newNode;
	start->prev = newNode;
	return (newNode);
}

/**
 * add_node_begin - Add node to the beginning of a double circular linked list.
 * @list: the list to modify
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode = NULL;
	char *nodeStr;

	if (!list || *list == NULL)
	{
		newNode = (List *) malloc(sizeof(List));
		if (!newNode)
			return (NULL);
		nodeStr = strdup(str);
		if (!nodeStr)
			return (NULL);
		newNode->str = nodeStr;
		newNode->prev = newNode;
		newNode->next = newNode;
		*list = newNode;
		return (newNode);
	}

	newNode = (List *) malloc(sizeof(List));
	if (!newNode)
		return (NULL);
	nodeStr = strdup(str);
	if (!nodeStr)
		return (NULL);
	newNode->str = nodeStr;
	newNode->next = (*list);
	if ((*list)->prev == NULL && (*list)->next == NULL)
	{
		(*list)->prev = newNode;
		(*list)->next = newNode;
		newNode->prev = (*list);
	}
	else
	{
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	*list = newNode;
	return (newNode);
}
