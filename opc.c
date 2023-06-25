#include "monty.h"

/**
 * swap - exchange places
 * @stack: linked list
 * @line_number: counter
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) stack;
	
	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = vars->h;
	current = temp->next;
	temp->next = current->next;
	if (temp->next)
		temp->next->prev = temp;
	current->next = temp;
	temp->prev = current;
	current->prev = NULL;
	vars->h = current;
}

/**
 * add - add top two element 
 * @stack: linked list
 * @line_number: counter
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) stack;
	
	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = vars->h;
	current = temp->next;
	current->n = temp->n + current->n;
	temp = vars->h;
	vars->h = temp->next;
	free(temp);
	vars->len -= 1;
}

/**
 * sub - substract the top two elements
 * @stack: linked list
 * @line_number: counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) stack;

	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
        temp = vars->h;
        current = temp->next;
        current->n = temp->n - current->n;
        temp = vars->h;
        vars->h = temp->next;
        free(temp);
        vars->len -= 1;	
}

/**
 * divi - divide the top two elements 
 * @stack: linked list
 * @line_number: counter
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h, *current = temp->next;
	(void) stack;

	if (vars->len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
        current->n = current->n / temp->n;
        temp = vars->h;
        vars->h = temp->next;
        free(temp);
        vars->len -= 1;
}
