#include "monty.h"

/**
 * check_pint - check if a string is pint
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_pint(char *str)
{
	char *a = NULL;

	if (str[0] != 'p')
		return (0);
	if (str[1] != 'i')
		return (0);
	if (str[2] != 'n')
		return (0);
	if (str[3] != 't')
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
 * pint - prints the top of a stack
 * @stack: head of stack
 * @ln: line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int ln)
{
	stack_t *cnt;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty",
						ln);
		exit(EXIT_FAILURE);
	}
	cnt = *stack;
	printf("%d\n", cnt->n);
}
