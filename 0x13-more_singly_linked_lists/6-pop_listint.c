#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 *               and returns the head node's data (n).
 * @head: Pointer to the pointer to the head of the list.
 * Return: The data (n) of the deleted head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp;

	if (*head != NULL)
	{
	/* Store the data of the head node to be returned */
	data = (*head)->n;

	/* Keep a temporary pointer to the head */
	temp = *head;

	/* Move the head pointer to the next node */
	*head = (*head)->next;

	/* Free the previous head node */
	free(temp);
	}
	return (data);
}
