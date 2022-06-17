#include "monty.h"

/**
 * validate_push - validates push opCode
 * @inst: instruction;
 * @line: line buffer
 * @ln: line Number
 * @file: file
 * @stack: stack
 *
 * Return: number to push
 */
int validate_push(char *line, instruction_t *inst,
				unsigned int ln, FILE *file, stack_t *stack)
{
	char *a = &(inst->opcode[5]);
	int n = 1, tmp;

	while (*a == ' ')
		a++;
	a = strtok(a, " ");
	if ((strcmp(a, "0\n") == 0) || (strcmp(a, "0") == 0)
					|| (strcmp(a, "-0\n") == 0) || (strcmp(a, "-0") == 0))
		n = 0;
	else
		tmp = atoi(a);
	while (*a != '\n' && *a != '\0')
	{
		if ((*a < '0' || *a > '9') && *a != '-' && *a != ' ')
			tmp = 0;
		a++;
	}
	if (tmp == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free(inst);
		tidy_up(line, 0, file, stack);
	}
	if (n != 0)
		n = tmp;
	return (n);
}
