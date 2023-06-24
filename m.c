#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define MAX_LINE_LENGTH 1024

/**
 * tokenize - check the code
 * @line: input
 * @tokens: separated by strtok
 */
void tokenize()
{
	int j = 0;
	char *token = NULL, *linecpy = NULL, *delims = " \n";

	linecpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(linecpy, arguments->line);
	arguments->i = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->i += 1;
		token = strtok(NULL, delims);
	}
	arguments->tokens = malloc(sizeof(char *) *(arguments->i + 1));
	strcpy(linecpy, arguments->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->tokens[j] = malloc(sizeof(char) *(strlen(token) + 1));
		if (arguments->tokens[j] == NULL)
			malloc_failed();
		strcpy(arguments->tokens[j], token);
		token = strtok(NULL, delims);
		j++;
	}
	arguments->tokens[j] = NULL;
	free(linecpy);
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
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{NULL, NULL}
	};
	if (arguments->i == 0)
		return;
	while (instructions[j].opcode != NULL)
	{
		if (strcmp(instructions[j].opcode, arguments->tokens[0]) == 0)
		{
			arguments->instruction->opcode = instructions[j].opcode;
			arguments->instruction->f = instructions[j].f;			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", arguments->line_number, arguments->tokens[0]);
	fclose(arguments->file);
	free_token();
	free_argument();
	exit(EXIT_FAILURE);
}

/**
 * push - add
 * @stack: struct
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->i <= 1 || !(is_number(arguments->tokens[1])))
	{
		free_argument();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(arguments->tokens[1]);
	if (arguments->head != NULL)
	{
		(*stack)->next = arguments->head;
		arguments->head->prev = *stack;
	}
	arguments->head = *stack;
	arguments->stack_length += 1;
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
	
	if (arguments->head == NULL)
		return;
	temp = arguments->head;
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
	arguments->file = fopen(argv[1], "r");
	if (!arguments->file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while (getline(&arguments->line, &n, arguments->file) != -1)
	{
		arguments->line_number += 1;
		tokenize();
		execute_instruction();
		run_instruction();
		free_token();
	}
	close_stream();
	free_argument();
	return (0);
}
