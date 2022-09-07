#include "monty.h"

/**
 * pall - pall items in the stack
 * @stack: stack
 * @line_number: the number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL;
	int i = 0;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	head = *stack;
	while (i < stack_size)
	{
		printf("%d\n", head->n);
		head = head->next;
		i++;
	}
}
