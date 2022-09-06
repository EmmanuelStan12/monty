#include "main.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall}
};

int stack_size = 0;

args_t args = {NULL, NULL, 0};

/**
 * main - Entry point
 *
 * Return: the status
 */
int main(int argc, char **argv)
{
	char **lines;
	int l_size, i;
	char *filename;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	l_size = lines_size(filename);
	lines = getlines(l_size, filename);
	for (i = 0; i < l_size; i++)
	{
		int t_size;
		char **tokens;

		t_size = token_size(lines[i], " ");
		tokens = tokenize(t_size, lines[i], " \n");

		args.tokens = tokens;
		args.opcode = tokens[0];
		args.t_size = t_size;
		execute(i, &stack);
		free(lines[i]);
		free_list(tokens);
	}
	free(lines);
	free_stack(&stack);
	return (0);
}
