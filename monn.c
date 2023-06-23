#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
stack_t *stack = NULL;
#define MAX_LINE_LENGTH 1024

/**
 * tokenize - check the code
 * @line: input
 * @tokens: separated by strtok
 */
void tokenize(char *line, char **tokens)
{
	char *token = strtok(line, " \t\n");
	int i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
}

/**
 * execute_instruction - call the functions
 * @tokens: separated input
 * @line_number: counter
 */

void execute_instruction(char **tokens, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, tokens[0]) == 0)
		{
			instructions[i].f(&stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
	exit(EXIT_FAILURE);
}

/**
 * push - add
 * @stack: struct
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *tokens[2] = {NULL};
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "Error: stack is NULL\n");
		exit(EXIT_FAILURE);
	}
	if (!tokens[1] || atoi(tokens[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(tokens[1]);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - check the code
 * @stack: struct
 * @line_number: counter
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

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
	char *tokens[4], line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		tokenize(line, tokens);
		execute_instruction(tokens, line_number);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
