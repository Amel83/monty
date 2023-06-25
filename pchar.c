#include "monty.h"
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h;
	(void) stack;

	if (vars->h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h;
	(void) stack;
	(void) line_number;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n >= 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h, *current = temp->next;
	(void) stack;
	(void) line_number;

	if (vars->len < 2)
		return;
	if (current)
	{
		while (current->next == NULL)
		{
			current->next = temp;
			temp->next= NULL;
			temp->prev = current;
			break;
		}
		current = current->next;
	}
}

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = vars->h, *end;
	(void) stack;
	(void) line_number;

	while (vars->len < 2)
		return;
	while (temp)
	{
		if (temp->next == NULL)
		{
			end = temp;
			break;
		}
		temp = temp->next;
	}
	end->prev->next = NULL;
	end->next = vars->h;
	end->prev = NULL;
	vars->h = end;
}

