#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 *
 * @root: pointer to the root of the binary tree
 * @value: is a double pointer to the root node of the Heap
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *test;
	test = insert_into_first_place(root, value);
	return test;
}


binary_tree_t *insert_into_first_place(heap_t **root, int value) {
	binary_tree_t *nn, *temp;
	temp = *root;
	if (temp)
	printf("%d", temp->n);
	if (temp == NULL)
	{
		nn = binary_tree_node(NULL, value);
		*root = nn;
		return nn;
	}
	else if (temp->left == NULL) 
    {
		nn = binary_tree_insert_left(temp, value);
		return nn;
	} 
	else if (temp->right == NULL) 
	{
		nn = binary_tree_insert_right(temp, value);
		return nn;
	}
    else
    { 
        insert_into_first_place(&temp->left, value); 
        insert_into_first_place(&temp->right, value); 
    }
	return NULL;
}


/**
* binary_tree_insert_left - Entry point
*
*
* @parent : The parent.
* @value : The value of the node.
* Return: Always 0 (Success)
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (!parent)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->n = value;
new->parent = parent;
new->left = parent->left;
new->right = NULL;
parent->left = new;
if (new->left)
new->left->parent = new;
return (new);
}

/**
* binary_tree_insert_right - Entry point
* @parent : The parent.
* @value : The value of the node.
* Return: Always 0 (Success)
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (!parent)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->n = value;
new->parent = parent;
new->right = parent->right;
new->left = NULL;
parent->right = new;
if (new->right)
new->right->parent = new;
return (new);
}
