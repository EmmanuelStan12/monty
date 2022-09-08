#include "monty.h"

/**
 * swap - swaps the top two elements of a stack
 * @stack: the stack
 * @line_number: the line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *next;

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = next;
	if (next)
		next->prev = first;
	*stack = second;
}
