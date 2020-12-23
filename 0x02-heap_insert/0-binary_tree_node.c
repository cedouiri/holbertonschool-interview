#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create Binary tree node
 *
 *
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nn;

	nn = malloc(sizeof(binary_tree_t));
	if (!nn)
	return (NULL);
	nn->left = NULL;
	nn->right = NULL;
	nn->parent = parent;
	nn->n = value;
	return (nn);
}
