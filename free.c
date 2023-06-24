#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
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

void close_file(void)
{
	if (vars->file == NULL)
		return;
	fclose(vars->file);
	vars->file = NULL;
}

void free_arguments()
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

void free_h(void)
{
	if (vars->h)
		free_stack(vars->h);
	vars->h = NULL;
}

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

void free_all(void)
{
	close_file();
	free_tokens();
	free_arguments();
}
