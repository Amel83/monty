#include <stdio.h>
#include "monty.h"
void initializes()
{
	vars = malloc(sizeof(var_t));
	if(vars == NULL)
		malloc_fail();
	vars->instruction = malloc(sizeof(instruction_t));
	if (vars->instruction == NULL)
		malloc_fail();

	vars->file = NULL;
	vars->input = NULL;
	vars->line_number = 1;
	vars->len = 0;
	vars->h = NULL;
	vars->stack = 1;
	vars->i = 0;
}

void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	vars->stack = 1;
}


void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	vars->stack = 0;
} 

void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

void run(void)
{
	stack_t *stack = NULL;

	if (vars->i == 0)
		return;
	vars->instruction->f(&stack, vars->line_number);
}
