#include "monty.h"

/**
 * clean_up - clean up application's resources
 * @line_number: the line to begin deleting from
 * @stack: the stack
 * Return: void
 */
void clean_up(stack_t **stack, int line_number)
{
	int i;

	free_list(args.tokens);
	free_stack(stack);
	for (i = line_number - 1; i < fd.no_of_lines; i++)
	{
		free(fd.lines[i]);
	}
	free(fd.lines);
}
