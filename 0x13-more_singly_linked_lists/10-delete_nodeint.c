#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the given
 *                index of a listint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev;
	unsigned int count;

	if (*head == NULL)
	return (-1);
	temp = *head;
	prev = NULL;
	count = 0;
	while (temp != NULL && count != index)
	{
	prev = temp;
	temp = temp->next;
	count++;
	}
	if (temp == NULL)
	return (-1);
	if (index == 0)
	*head = temp->next;
	else
	prev->next = temp->next;
	free(temp);
	return (1);
}
