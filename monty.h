#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct vars - global variables
 * @file: file
 * @tokens:array of inputs
 * @input: read line from file
 * @i: int
 * @h: head of linked list
 * @len: int counter
 * @stack: linked list
 * @instruction: orders
 * @line_number: counter
 */

typedef struct vars
{
	FILE *file;
	char **tokens;
	char *input;
	int i;
	stack_t *h;
	int len;
	int stack;
	instruction_t *instruction;
	unsigned int line_number;
} var_t;

var_t *vars;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int is_digit(char *str);
void free_tokens(void);
void close_file(void);
void malloc_fail(void);
void execute_instruction(void);
void tokenize(void);
void initializes(void);
void run(void);
void free_all(void);
void free_arguments(void);
void free_stack(stack_t *head);
void free_h(void);

#endif
