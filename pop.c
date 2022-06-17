#include "monty.h"

/**
 * check_pop - check if a string is pint
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_pop(char *str)
{
	char *a = NULL;

	if (str[0] != 'p')
		return (0);
	if (str[1] != 'o')
		return (0);
	if (str[2] != 'p')
		return (0);
	if (str[3] != ' ' && str[3] != '\0' && str[3] != '\n')
		return (0);
	while (*a != '\0' && *a != '\n')
	{
		if (*a != ' ')
			return (0);
		a++;
	}
	return (1);
}

/**
 * pop - prints the top of a stack
 * @stack: head of stack
 * @ln: line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *cnt;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
						ln);
		exit(EXIT_FAILURE);
	}
	cnt = *stack;
	*stack = cnt->next;
	free(cnt);
}
