#include "monty.h"

/**
 * check_add - check if a string is pint
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_add(char *str)
{
	if (str[0] != 'a')
		return (0);
	if (str[1] != 'd')
		return (0);
	if (str[2] != 'd')
		return (0);
	if (str[3] != ' ' && str[3] != '\0' && str[3] != '\n')                                                                 
		return (0);
	return (1);
}

/**
 * check_nop - check if a string is pint
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_nop(char *str)
{
	if (str[0] != 'n')
		return (0);
	if (str[1] != 'o')
		return (0);
	if (str[2] != 'p')
		return (0);
	if (str[3] != ' ' && str[3] != '\0' && str[3] != '\n')
		return (0);
	return (1);
}

/**
 * add - prints the top of a stack
 * @stack: head of stack
 * @ln: line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *h, *cnt;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,
			"L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	cnt = h->next;
	if (cnt == NULL)
	{
		fprintf(stderr,
			"L%d: can't add, stack too short\n", ln);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	cnt->prev = NULL;
	cnt->n += h->n;
	*stack = cnt;
	free(h);
}
