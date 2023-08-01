#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;
	int is_loop = 0;

	while (current != NULL)
	{
	printf("[%p] %d\n", (void *)current, current->n);
	count++;
	if ((void *)current <= (void *)(current->next))
	{
	is_loop = 1;
	break;
	}
	current = current->next;
	}
	if (is_loop)
	{
	printf("-> [%p] %d\n", (void *)current, current->n);
	printf("loop starts at [%p]\n", (void *)current);
	}
	return (count);
}
