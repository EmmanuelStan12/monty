#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	fprintf(stdout, "%d\n", head->n);
}
