#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binay tree using post order traversal
 * @tree : pointer to the tree node
 * @func : pointer to a function to call for each node
 *
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
