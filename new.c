#include <stdio.h>
#include "monty.h"

/**
 * initializes - the name tells
 */
void initializes(void)
{
	vars = malloc(sizeof(var_t));
	if (vars == NULL)
		malloc_fail();
	vars->instruction = malloc(sizeof(instruction_t));
	if (vars->instruction == NULL)
		malloc_fail();

	vars->file = NULL;
	vars->input = NULL;
	vars->line_number = 0;
	vars->len = 0;
	vars->h = NULL;
	vars->stack = 1;
	vars->i = 0;
}

/**
 * stack - to change from queu to stack
 * @stack: struct
 * @line_number: counter
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	vars->stack = 1;
}

/**
 * queue - to change to queue from stack
 * @stack: struct
 * @line_number: counter
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	vars->stack = 0;
}

/**
 * malloc_fail - error output
 */

void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * run - check code
 */

void run(void)
{
	stack_t *stack = NULL;

	if (vars->i == 0)
		return;
	vars->instruction->f(&stack, vars->line_number);
}
