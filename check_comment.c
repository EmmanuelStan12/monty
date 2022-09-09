#include "monty.h"

/**
 * check_comment - checks for comments in the line
 * @line: the line to be checked
 * Return: 1 or 0
 */
int check_comment(char *line)
{
	int i, _size = 0;

	_size = strlen(line);
	for (i = 0; isspace(line[i]) && i < _size; i++)
		;
	if (i == _size && isspace(line[i - 1]))
		return (1);
	if (line[i] == '#')
		return (1);
	return (0);
}
