#include "monty.h"

/**
 * print_stack - prints all the elements of a stack
 * @stack: head of the list
 * @line_number: line number
 *
 * Return: number of nodes in the stack
 */
void print_stack(stack_t **stack, __attribute__((unused))
			   unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL)
		return;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
