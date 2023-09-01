#include "binary_trees.h"

/**
 * depthofnode - helper function to get the depth of a node
 * @node: pointer to the node to the node to get depth
 *
 * Return: depth
 */
size_t depthofnode(binary_tree_t *node)
{
	size_t depth = 0;

	while (node)
	{
		node = node->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor else NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *firstn = (binary_tree_t *)first;
	binary_tree_t *secondn = (binary_tree_t *)second;
	size_t firstd, secondd;

	if (firstn == NULL || secondn == NULL)
		return (NULL);

	if (firstn == NULL && secondn == NULL)
		return (NULL);
	/*if the nodes are not same , traverse them to get lowets anccestor*/
	while (firstn != secondn)
	{
		firstd = depthofnode(firstn);
		secondd = depthofnode(secondn);
		/*makes sure the nodes are on same level*/
		while (firstd > secondd)
		{
			firstn = firstn->parent;
			firstd--;
		}
		while (secondd > firstd)
		{
			secondn = secondn->parent;
			secondd--;
		}
		/*check if the nodes are not equal to move to their parents*/
		if (firstn != secondn)
		{
			firstn = firstn->parent;
			secondn = secondn->parent;
		}
	}
	return (firstn);
}

