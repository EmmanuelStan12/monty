#include "monty.h"

/**
 * pop - pops the first element of the stack
 * @stack: the stack
 * @line_number: the line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL, *next;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head->next != NULL)
	{
		next = head->next;
		next->prev = NULL;
		head->next = NULL;
		*stack = next;
	}
	else
	{
		*stack = NULL;
	}
	free(head);
	stack_size -= 1;
}
