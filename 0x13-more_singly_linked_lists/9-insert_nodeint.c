#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node
 *                 at a given position in a listint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @idx: The index of the list where the new node
 *               should be added. Index starts at 0.
 * @n: Value to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp = *head;
	unsigned int count = 0;

	/* Create a new node and allocate memory for it */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	/* Set the value of the new node to the given integer */
	new_node->n = n;

	/* If the new node should be inserted at the beginning of the list */
	if (idx == 0)
	{
	new_node->next = *head;
	*head = new_node;
	return (new_node);
	}

	/* Traverse the list to find the node before the given index */
	while (count < idx - 1 && temp != NULL)
	{
	temp = temp->next;
	count++;
	}

	/* If the index is out of range or the list is empty */
	if (temp == NULL)
	{
	free(new_node);
	return (NULL);
	}

	/* Link the new node to the next node after the given index */
	new_node->next = temp->next;
	temp->next = new_node;

	/* Return the address of the new element (the new node) */
	return (new_node);
}
