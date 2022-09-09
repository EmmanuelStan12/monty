#include "monty.h"

/**
 * rotr- rotates the whole stack
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *prev, *current, *last;

	if (stack_size < 1)
	{
		return;
	}
	if (stack_size == 2)
	{
		swap(stack, line_number);
		return;
	}
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	last = current;
	while (current != NULL)
	{
		prev = current->prev;
		current->prev = current->next;
		current->next = prev;
		current = prev;
	}
	*stack = last;
}
