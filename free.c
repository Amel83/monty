#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_token(void)
{
	int j = 0;

	if (arguments->tokens == NULL)
		return;
	while (arguments->tokens[j])
	{
		free(arguments->tokens[j]);
		j++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}

void close_stream(void)
{
	if (arguments->file == NULL)
		return;
	fclose(arguments->file);
	arguments->file = NULL;
}

void free_argument()
{
	if (arguments == NULL)
		return;
	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}
	free_head();
	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}
	free(arguments);
}

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);
	arguments->head = NULL;
}

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

void free_all(void)
{
	close_stream();
	free_token();
	free_argument();
}
