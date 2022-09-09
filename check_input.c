#include "monty.h"

/**
 * check_input - checks of the input is an int
 * @input: the input to check
 * @line_no: the line of the command
 * @stack: the stack
 * Return: the number
 */
int check_input(stack_t **stack, char *input, int line_no)
{
	int num, i;

	if (input == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		clean_up(stack, line_no);
		exit(EXIT_FAILURE);
	}
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] < 48 || input[i] > 57)
		{
			if (i == 0 && input[i] == '-')
				continue;
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			clean_up(stack, line_no);
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(input, "0") == 0)
		return (0);
	num = atoi(input);
	return (num);
}
