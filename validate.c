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
	int n, tmp;
	
	if (*a == '0' && (a[1] == '\0' || a[1] == '\n'))
		n = 0;
	else
		tmp = atoi(a);
	if (tmp == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free(inst);
		tidy_up(line, 0, file, stack);
	}
	n = tmp;
	return (n);
}
