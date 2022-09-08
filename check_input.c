#include "monty.h"

/**
 * check_input - checks of the input is an int
 * @input: the input to check
 * @line_no: the line of the command
 * Return: the number
 */
int check_input(char *input, int line_no)
{
	int num;

	if (input == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (strcmp(input, "0") == 0)
		return (0);
	num = atoi(input);
	if (num == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	return (num);
}
