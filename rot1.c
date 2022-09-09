#include "monty.h"

/**
 * rot1 - rotates the whole stack by 1
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void rot1(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last, *current, *second;

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
	second = first->next;
	second->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = second;
}
