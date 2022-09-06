#include "main.h"

/**
 * free_stack - frees items in the stack
 * @stack: stack
 * @line_number: the number
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *head, *temp = NULL;
	int i = 0;

	if (stack == NULL)
		return;
	head = *stack;
	while (i < stack_size)
	{
		printf("%d\n", head->n);
		temp = head->next;
		free(head);
		head = temp;
		i++;
	}
	free(head);
}
