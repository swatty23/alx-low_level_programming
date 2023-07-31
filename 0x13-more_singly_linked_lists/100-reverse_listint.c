#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next_node;

	while (*head != NULL)
	{
	next_node = (*head)->next;
	(*head)->next = prev;
	prev = *head;
	*head = next_node;
	}
	return (prev);
}
