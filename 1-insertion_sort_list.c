#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to a pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Swap nodes */
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev != NULL)
				current->prev->next = current;

			current->next->prev = current;

			/* Update head if necessary */
			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}

		current = next_node;
	}
}
