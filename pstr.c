#include "monty.h"

/**
 * pstr - prints the string
 * @stack: the stack
 * @line_number: the line_number
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int num;

	if (stack_size < 1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		clean_up(stack, line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	num = current->n;
	while ((num >= 97 && num <= 122) || (num >= 65 && num <= 90))
	{
		putchar(num);
		if (!current->next)
		{
			break;
		}
		current = current->next;
		num = current->n;
	}
	putchar('\n');
}
