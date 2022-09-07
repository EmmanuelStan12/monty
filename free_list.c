#include "monty.h"

/**
 * free_list - frees content of a list
 * @lines: the lines
 * Return: void
 */
void free_list(char **lines)
{
	int i = 0;

	if (lines)
	{
		while (lines[i])
		{
			free(lines[i]);
			i++;
		}
		free(lines);
	}
}
