#include "monty.h"

/**
 * push - add a new node at the beginning of a stack
 * @head: pointer to pointer of the head node
 * @n: the item for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *h = NULL, *temp;

	if (head == NULL)
		return (NULL);
	h = malloc(sizeof(stack_t));
	if (h == NULL)
		return (NULL);
	temp = *head;
	h->n = n;
	h->prev = NULL;
	h->next = temp;
	if (temp != NULL)
		temp->prev = h;
	*head = h;

	return (h);
}

