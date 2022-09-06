#include "main.h"
/**
 * execute - executes a command
 * @size: the no of tokens in string
 * @tokens: the tokens
 * @stack: the stack
 * Return: void
 */
void execute(int line_no, stack_t **stack)
{
	int i;
	args_t a = args;

	for (i = 0; i < INSTRUCTION_SIZE; i++)
	{
		int result = strcmp(a.tokens[0], instructions[i].opcode);

		if (result == 0)
		{
			instructions[i].f(stack, line_no);
			break;
		}
	}
}
