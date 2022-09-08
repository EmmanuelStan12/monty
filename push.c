#include "monty.h"

/**
 * push - push an item to the stack
 * @stack: stack
 * @line_number: the number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *item;
	int num;

	item = malloc(sizeof(stack_t));
	if (item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	num = check_input(stack, args.tokens[1], line_number);
	item->n = num;
	item->prev = NULL;
	if (*stack == NULL)
	{
		item->next = NULL;
		*stack = item;
	}
	else
	{
		head = *stack;
		head->prev = item;
		item->next = head;
		*stack = item;
	}
	stack_size += 1;
}
