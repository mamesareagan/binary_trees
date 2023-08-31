#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent:pointer to the node to insert the left-child in
 * @value:value to store in the new node
 *
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode, *current;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL || parent == NULL)
	{
		return (NULL);
	}
	newnode->n = value;
	newnode->parent =  parent;
	newnode->left = NULL;
	newnode->right = NULL;
	if (parent->left)
	{
		current = parent->left;
		current->parent = newnode;
		newnode->left = current;
		parent->left = newnode;
	}
	else
	{
		parent->left = newnode;
	}
	return (newnode);
}
