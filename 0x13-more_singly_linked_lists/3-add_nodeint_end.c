#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @n: Value to be stored in the new node.
 * Return: The address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;
	/* Create a new node and allocate memory for it */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	/* Set the value of the new node to the given integer */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, make the new node the head of the list */
	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	/* Traverse the list to find the last node */
	temp = *head;
	while (temp->next != NULL)
	{
	temp = temp->next;
	}
	/* Link the last node to the new node */
	temp->next = new_node;
	}
	/* Return the address of the new element (the new node) */
	return (new_node);
}
