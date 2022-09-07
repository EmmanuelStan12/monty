#include "monty.h"

/**
 * sub - subtracts the top element from the second in the stack
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	result = second->n - first->n;
	first->next = NULL;
	second->prev = NULL;
	free(first);
	second->n = result;
	stack_size -= 1;
	*stack = second;
}
