#include "main.h"

/**
 * getlines - gets the lines and returns them
 * @filename: the name of the file
 * @no_of_lines: the no of lines
 * Return: list of lines
 */
char **getlines(int no_of_lines, char *filename)
{
	FILE *file;
	char *line = NULL;
	ssize_t rstatus;
	size_t size = 0;
	char **lines;
	int i = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error:");
		exit(EXIT_FAILURE);
	}
	lines = malloc(no_of_lines * sizeof(char *));
	while ((rstatus = getline(&line, &size, file)) != -1)
	{
		lines[i++] = strdup(line);
	}
	free(line);
	fclose(file);
	return (lines);
}
