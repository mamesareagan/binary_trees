#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - meausres the height of a binary tree
 * @tree: pointer to thr root node of the tree
 *
 * Return: 0 if tree is NULL else height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lefth, righth;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	lefth = binary_tree_height(tree->left);
	righth = binary_tree_height(tree->right);
	if (lefth > righth)
		return (lefth + 1);
	else
		return (righth + 1);
}
