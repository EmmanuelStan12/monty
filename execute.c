#include "monty.h"

/**
 * execute - executes a command
 * @line_no: the line number
 * @stack: the stack
 * Return: void
 */
void execute(int line_no, stack_t **stack)
{
	int i, seen = 0;
	args_t a = args;

	for (i = 0; i < INSTRUCTION_SIZE; i++)
	{
		int result = strcmp(a.tokens[0], instructions[i].opcode);

		if (result == 0)
		{
			instructions[i].f(stack, line_no);
			seen = 1;
			break;
		}
	}
	if (!seen)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_no, a.tokens[0]);
		exit(EXIT_FAILURE);
	}
}
