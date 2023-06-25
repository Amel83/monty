#include "monty.h"

/**
 * mul - multiplication
 * @stack: linked list struct
 * @line_number: counter
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) stack;

	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = vars->h;
	current = temp->next;
	current->n = temp->n * current->n;
	temp = vars->h;
	vars->h = current;
	free(temp);
	vars->len -= 1;
}

/**
 * nop - do nothing
 * @stack: linked list struct
 * @line_number: counter
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * mod - divide the top two elements
 * @stack: linked list
 * @line_number: counter
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h, *current = temp->next;
	(void) stack;

	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	current->n = current->n % temp->n;
	temp = vars->h;
	vars->h = current;
	free(temp);
	vars->len -= 1;
}
