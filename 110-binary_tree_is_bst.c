#include "binary_trees.h"
#include <limits.h>

/**
 * isBSTUtil - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */

int isBSTUtil(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (isBSTUtil(tree->left, min, tree->n - 1) &&
		isBSTUtil(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isBSTUtil(tree, INT_MIN, INT_MAX));
}
