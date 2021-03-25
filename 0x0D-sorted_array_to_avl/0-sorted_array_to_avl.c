#include "binary_trees.h"


/**
 * create_node - Creates node
 * @array: pointer that point to the first of the array
 * @parent: pointer that point to the parent
 * @start: start ind of the subarray
 * @end: end ind of subarray
 * Return: pointer to the address of AVL
 */
avl_t *create_node(int *array, avl_t *parent, int start, int end)
{
	avl_t *Node;
	int middle;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	Node = malloc(sizeof(avl_t));

	if (!Node)
		return (NULL);

	Node->n = array[middle];
	Node->parent = parent;
	Node->left = create_node(array, Node, start, middle - 1);
	Node->right = create_node(array, Node, middle + 1, end);

	return (Node);
}


/**
 * sorted_array_to_avl - sorted array to AVL
 * @array: array to be converted
 * @size: size of array
 * Return: the head of AVL Tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int middle, start, end;
	avl_t *head;

	if (!array)
	return (NULL);

	start = 0;
	end = size - 1;
	middle = (start + end) / 2;

	head = malloc(sizeof(avl_t));
	if (!head)
	return (NULL);
	head->n = array[middle];
	head->parent = NULL;
	head->left = create_node(array, head, start, middle - 1);
	head->right = create_node(array, head, middle + 1, end);
	return (head);
}
