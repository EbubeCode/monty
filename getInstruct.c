#include "monty.h"

/**
 * check_push - check if a string is equal to push
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_push(char *str)
{
	if (str[0] != 'p')
		return (0);
	if (str[1] != 'u')
		return (0);
	if (str[2] != 's')
		return (0);
	if (str[3] != 'h')
		return (0);
	if (str[4] != ' ')
		return (0);

	return (1);
}

/**
 * check_pall - check if a string is equal to pall
 * @str: string
 *
 * Return: 1 true or 0 false
 */
int check_pall(char *str)
{
	char *a = NULL;

	if (str[0] != 'p')
		return (0);
	if (str[1] != 'a')
		return (0);
	if (str[2] != 'l')
		return (0);
	if (str[3] != 'l')
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
* get_opcode - extracts opcode from a line
* @line: line to search
* @ln: line number
*
* Return: opcode or NULL
*/
char *get_opcode(char *line, int ln)
{
	char *a = line;

	while (*a != '\n' && *a != '\0')
	{
		if (*a != ' ')
		{
			if (check_push(a))
				return (a);
			else if (check_pall(a))
				return (a);
			else if (check_pint(a))
				return (a);
			fprintf(stderr, "L%d: unknown instruction %s", ln, a);
			return (NULL);
		}
		a++;
	}
	return (a);
}


/**
 * tidy_up - tidies up
 * @line: buffer read
 * @status: status
 * @file: file
 * @stack: stack
 *
 * Return: void
 */
void tidy_up(char *line, int status, FILE *file, stack_t *stack)
{
	fclose(file);
	free(line);
	free_stack(stack);
	if (status)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

/**
 * getInstruct - getsInstruction from a file
 * @file: file
 * @ln: pointer to line number
 * @line: line
 * @stack: stack
 *
 * Return: pointer to instruction
 */
instruction_t *getInstruct(FILE *file, char *line,
				unsigned int ln, stack_t *stack)
{
	char *opCode;
	instruction_t *inst = NULL;

	opCode = get_opcode(line, ln);
	if (opCode == NULL)
		tidy_up(line, 0, file, stack);
	if (*opCode == '\0' || *opCode == '\n')
		return (NULL);
	inst = malloc(sizeof(instruction_t *));
	if (inst == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		tidy_up(line, 0, file, stack);
	}
	inst->opcode = opCode;
	if (check_push(opCode))
		inst->f = NULL;
	else if (check_pint(opCode))
		inst->f = pint;
	else
		inst->f = print_stack;
	return (inst);
}
