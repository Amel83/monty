#include <stdio.h>
#include "monty.h"
void initializes()
{
	arguments = malloc(sizeof(arg_t));
	if(arguments == NULL)
		malloc_failed();
	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->file = NULL;
	arguments->line = NULL;
	arguments->line_number = 1;
	arguments->stack_length = 0;
	arguments->head = NULL;
	arguments->i = 0;
}

void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_argument();
	exit(EXIT_FAILURE);
}

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->i == 0)
		return;
	arguments->instruction->f(&stack, arguments->line_number);
}
