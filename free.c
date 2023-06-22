#include "monty.h"
/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->line = NULL;
	var->i = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->h = NULL;
	var->line_number = 1;
	
	return (EXIT_SUCCESS);
}

/**
 * create_instru - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instru()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[9].opcode = "mul", ptr[9].f = mul;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[14].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - Call Functions
 * @var: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int calller(vars *var, char *opcode)
{
	int j;

	for (j = 0; var->dict[j].token; j++)
		if (strcmp(token, var->dict[j].token) == 0)
		{
			if (!var->dict[j].f)
				return (EXIT_SUCCESS);
			var->dict[j].f(&var->h, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(token) != 0 && token[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, token);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void freeing(void)
{
	if (var.line != NULL)
		free(var.line);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.h != NULL)
	{
		while (var.h->next != NULL)
		{
			var.h = var.h->next;
			free(var.h->prev);
		}
		free(var.h);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int j;

	for (j = 0; string[j]; j++)
	{
		if (string[j] < 48 || string[j] > 57)
			return (1);
	}
	return (0);
}
