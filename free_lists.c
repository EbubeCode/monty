#include "monty.h"


/**
 * free_stack - frees the memory help by a stack
 * @head: pointer to head of list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
