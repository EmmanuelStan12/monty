#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int num;

	if (stack_size < 1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	num = first->n;
	if ((num >= 97 && num <= 122) || (num >= 65 && num <= 90))
	{
		printf("%c\n", num);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
}
