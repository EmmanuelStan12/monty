#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", _div},
	{"mul", mul},
	{"mod", mod}
};

int stack_size = 0;

args_t args = {NULL, NULL, 0};

file_details fd = {NULL, 0};

/**
 * main - Entry point
 * @argc: the no of arguments
 * @argv: the arguments
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
	fd.lines = lines;
	fd.no_of_lines = l_size;
	for (i = 0; i < l_size; i++)
	{
		int t_size;
		char **tokens;

		if (lines[i][0] == '#')
		{
			free(lines[i]);
			continue;
		}
		t_size = token_size(lines[i], " ");
		tokens = tokenize(t_size, lines[i], " \n");
		args.tokens = tokens;
		args.opcode = tokens[0];
		args.t_size = t_size;
		execute(i + 1, &stack);
		free(lines[i]);
		free_list(tokens);
	}
	free(lines);
	free_stack(&stack);
	return (0);
}
