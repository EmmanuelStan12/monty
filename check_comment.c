#include "monty.h"

/**
 * check_comment - checks for comments in the line
 * @line: the line to be checked
 * Return: 1 or 0
 */
int check_comment(char *line)
{
	int i;

	for (i = 0; isspace(line[i]); i++);
	if (line[i] == '#')
	{
		return (1);
	}
	return (0);
}
