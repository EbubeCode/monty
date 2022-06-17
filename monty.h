#ifndef MONTY_H
#define MONTY_H


#include <stdlib.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *head);
stack_t *push(stack_t **head, int n);
instruction_t *getInstruct(FILE *file, char *line,
				unsigned int ln, stack_t *stack);
int check_pall(char *str);
int check_push(char *str);
void print_stack(stack_t **, unsigned int);
int validate_push(char *, instruction_t *, unsigned int,
				FILE *file, stack_t *stack);
void tidy_up(char *line, int status, FILE *file, stack_t *);

#endif
