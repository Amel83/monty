#include "monty.h"
/**
* free_tokens - frees a doubly linked list
*/

void free_tokens(void)
{
	int j = 0;

	if (vars->tokens == NULL)
		return;
	while (vars->tokens[j])
	{
		free(vars->tokens[j]);
		j++;
	}
	free(vars->tokens);
	vars->tokens = NULL;
}

/**
 * free_arguments - as the name says
 */

void free_arguments(void)
{
	if (vars == NULL)
		return;
	if (vars->instruction)
	{
		free(vars->instruction);
		vars->instruction = NULL;
	}
	free_h();
	if (vars->input)
	{
		free(vars->input);
		vars->input = NULL;
	}
	free(vars);
}

/**
 * free_h - free head
 */

void free_h(void)
{
	if (vars->h)
		free_stack(vars->h);
	vars->h = NULL;
}

/**
 * free_stack - check the code
 * @h: linked list
 */

void free_stack(stack_t *h)
{
	if (h == NULL)
		return;
	if (h->next != NULL)
	{
		free_stack(h->next);
	}
	free(h);
}

/**
 * free_all - check
 */

void free_all(void)
{
	close_file();
	free_tokens();
	free_arguments();
}
