#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * tokenize - check the code
 * @line: input
 * @tokens: separated by strtok
 */
void tokenize()
{
	int j = 0;
	char *token = NULL, *inputcpy = NULL, *delims = " \n";

	inputcpy = malloc(sizeof(char) * (strlen(vars->input) + 1));
	strcpy(inputcpy, vars->input);
	vars->i = 0;
	token = strtok(inputcpy, delims);
	while (token)
	{
		vars->i += 1;
		token = strtok(NULL, delims);
	}
	vars->tokens = malloc(sizeof(char *) *(vars->i + 1));
	strcpy(inputcpy, vars->input);
	token = strtok(inputcpy, delims);
	while (token)
	{
		vars->tokens[j] = malloc(sizeof(char) *(strlen(token) + 1));
		if (vars->tokens[j] == NULL)
			malloc_fail();
		strcpy(vars->tokens[j], token);
		token = strtok(NULL, delims);
		j++;
	}
	vars->tokens[j] = NULL;
	free(inputcpy);
}

/**
 * execute_instruction - call the functions
 * @tokens: separated input
 * @line_number: counter
 */

void execute_instruction()
{
	int j = 0;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pop", &pop},
		{"pint", &pint},
		{"swap", &swap},
		{"add", &add},
		{"sub", &sub}, {"pchar", &pchar}, 
		{"div", &divi}, {"mod", &mod},
		{"nop", &nop}, {"mul", &mul},
		{NULL, NULL}
	};
	if (vars->i == 0)
		return;
	while (vars->tokens[0][0] == '#')
	{
		vars->instruction->opcode = "nop";
		vars->instruction->f = nop;
		return;
	}
	while (instructions[j].opcode != NULL)
	{
		if (strcmp(instructions[j].opcode, vars->tokens[0]) == 0)
		{
			vars->instruction->opcode = instructions[j].opcode;
			vars->instruction->f = instructions[j].f;			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", vars->line_number, vars->tokens[0]);
	fclose(vars->file);
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * push - add
 * @stack: struct
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (vars->i <= 1 || !(is_digit(vars->tokens[1])))
	{
		free_arguments();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_fail();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(vars->tokens[1]);
	if (vars->h == NULL)
		vars->h = *stack;
	else
	{
		if (vars->stack)
		{
			(*stack)->next = vars->h;
			vars->h->prev = *stack;
			vars->h = *stack;
		}
		else
		{
			temp = vars->h;
			while(temp->next)
				temp = temp->next;
			temp->next = *stack;
			(*stack)->prev = temp;
		}
	}
	vars->len += 1;
}

/**
 * pall - check the code
 * @stack: struct
 * @line_number: counter
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;
	(void) line_number;
	
	if (vars->h == NULL)
		return;
	temp = vars->h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * main - check the code
 * @argc: cointer
 * @argv: arguments input
 * Return: int
 */

int main(int argc, char **argv)
{
	size_t n = 0;
	(void) argv;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initializes();
	vars->file = fopen(argv[1], "r");
	if (!vars->file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while (getline(&vars->input, &n, vars->file) != -1)
	{
		vars->line_number += 1;
		tokenize();
		execute_instruction();
		run();
		free_tokens();
	}
	close_file();
	free_arguments();
	return (0);
}
