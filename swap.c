#include "monty.h"

/**
 * check_swap - check if a string is pint
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_swap(char *str)
{
	char *a = NULL;

	if (str[0] != 's')
		return (0);
	if (str[1] != 'w')
		return (0);
	if (str[2] != 'a')
		return (0);
	if (str[3] != 'p')
		return (0);
	a = &str[4];
	while (*a != '\0' && *a != '\n')
	{
		if (*a != ' ')
			return (0);
		a++;
	}
	return (1);
}

/**
 * swap - prints the top of a stack
 * @stack: head of stack
 * @ln: line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *h, *cnt;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,
			"L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	cnt = h->next;
	if (cnt == NULL)
	{
		fprintf(stderr,
			"L%d: can't swap, stack too short\n", ln);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h->next = cnt->next;
	h->prev = cnt;
	cnt->next = h;
	cnt->prev = NULL;
	*stack = cnt;
}
