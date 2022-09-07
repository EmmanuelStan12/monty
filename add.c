#include "monty.h"

/**
 * add - adds the first two elements of the stack
 * @stack: the stack
 * @line_number: the number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int sum;

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	sum = first->n + second->n;
	first->next = NULL;
	second->prev = NULL;
	free(first);
	stack_size -= 1;
	second->n = sum;
	*stack = second;
}
