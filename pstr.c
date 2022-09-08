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
	(void) line_number;

	current = *stack;
	while (current)
	{
		num = current->n;
		if ((num >= 97 && num <= 122) || (num >= 65 && num <= 90))
		{
			putchar(num);
		}
		else
		{
			break;
		}
		current = current->next;
	}
	putchar('\n');
}
