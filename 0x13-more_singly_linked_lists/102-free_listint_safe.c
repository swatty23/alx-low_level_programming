#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the pointer to the head of the list.
 * Return: The size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t count = 0;

	while (current != NULL)
	{
	count++;
	temp = current->next;
	free(current);
	current = temp;
	if (current == *h)
	{
	*h = NULL;
	return (count);
	}
	}
	*h = NULL;
	return (count);
}
