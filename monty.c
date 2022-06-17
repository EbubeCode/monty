#include "monty.h"

/**
 * getLine - getlines in a file
 * @file: file
 * @stack: stack
 *
 * Return: line gotten
 */
char *getLine(FILE *file, stack_t *stack)
{
	char *line = malloc(sizeof(char) * 128);
	char *a;

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		tidy_up(NULL, 0, file, stack);
	}
	a = fgets(line, 128, file);
	if (a == NULL)
		tidy_up(line, 1, file, stack);
	return (line);
}
/**
 * main - entry point of application
 * @ac: number of command line arguments
 * @av: array of arguments
 *
 * Return: 0 successfull or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	FILE *file = NULL;
	unsigned int ln = 1;
	char *line = NULL;
	instruction_t *inst = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = getLine(file, stack);
		inst = getInstruct(file, line, ln, stack);
		if (inst != NULL)
		{
			if (check_push(inst->opcode))
				push(&stack, validate_push(line, inst,
										ln, file, stack));
			else
				inst->f(&stack, ln);
			free(inst);
		}
		ln++;
		if (line != NULL)
			free(line);
	}
}
