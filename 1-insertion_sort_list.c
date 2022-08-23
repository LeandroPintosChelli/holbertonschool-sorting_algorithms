#include "sort.h"
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2);
/**
* insertion_sort_list - sorts a doubly linked list using
* insertion sort algorithm.
* @list: pointer to a head of doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		insert = node->prev;
		while (insert != NULL && node->n < insert->n)
		{
			swap_nodes(list, &insert, node);
			print_list((const listint_t *)*list);
		}
	}
}


/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}
