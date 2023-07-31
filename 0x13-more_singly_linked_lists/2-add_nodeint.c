#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @n: Value to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	/* Create a new node and allocate memory for it */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	/* Set the value of the new node to the given integer */
	new_node->n = n;

	/* Point the new node to the current head of the list */
	new_node->next = *head;

	/* Update the head to point to the new node, making it the new head */
	*head = new_node;

	/* Return the address of the new element (the new node) */
	return (new_node);
}
