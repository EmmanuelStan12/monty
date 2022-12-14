#include "monty.h"

/**
 * rotr - rotates the whole stack by right
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last, *current, *second_to_the_last;

	if (stack_size <= 1)
		return;
	if (stack_size == 2)
	{
		swap(stack, line_number);
		return;
	}
	first = *stack;
	current = first;
	while (current->next != NULL)
	{
		current = current->next;
	}
	last = current;
	second_to_the_last = last->prev;
	second_to_the_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	*stack = last;
}
