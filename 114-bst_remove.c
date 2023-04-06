#include "binary_trees.h"

/**
 * minValueNode - retrieves the minimum node value
 * @node: node to find min value leaf
 *
 * Return: pointer to minimum value
 */

bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a binary tree
 * @root: pointer to the root node of the BST to remove a node
 * @value: value to remove from the tree
 * Once located, the node containing the value must be removed and freed
 * If the node to be deleted has two children, it must be replaced with its
 * first in-order successor (not predecessor)
 *
 * Return: pointer to the new root of the tree after removing the desired node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		else
		{
			temp = minValueNode(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
