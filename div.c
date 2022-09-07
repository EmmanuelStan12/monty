#include "monty.h"

/**
 * div - div the second element by the first element
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	result = second->n / first->n;
	first->next = NULL;
	second->prev = NULL;
	free(first);
	second->n = result;
	stack_size -= 1;
	*stack = second;
}
