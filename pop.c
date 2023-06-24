#include <ctype.h>
#include "monty.h"

/**
 * pint - print last node
 * @stack: linked list
 * @line_number: counter
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (vars->h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", vars->h->n);
}
/**
* pop - delete top of list
* @stack: double linked list
* @line_number: counter
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;

	if (vars->h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = vars->h;
	vars->h = temp->next;
	
	free(temp);
}

/**
 * is_number - check if a string is a valid integer
 * @str: input string
 * Return: 1 if valid integer, 0 otherwise
 */
int is_digit(char *str)
{
	int j = 0;

	while (str[j])
	{
		if (j == 0 && str[j] == '-' && str[j + 1])
		{
			j++;
			continue;
		}
		if (str[j] < '0' || str[j] > '9')
			return(0);
		j++;
	}
	return (1);
}
