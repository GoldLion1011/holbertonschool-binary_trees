#include "binary_trees.h"
#include <limits.h>

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the root node.
 * If the value is already present in the tree, it must be ignored
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	bst_t *current = NULL;

	if (tree == NULL)
		return (NULL);
	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	current = *tree;
	while (current != NULL)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->right;
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	return (NULL);
}
