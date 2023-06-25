#include "monty.h"
/**
 * close_file - check
 */

void close_file(void)
{
	if (vars->file == NULL)
		return;
	fclose(vars->file);
	vars->file = NULL;
}
