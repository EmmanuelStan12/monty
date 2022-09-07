#include "monty.h"

/**
 * lines_size - gets the number of lines
 * @filename: the filename
 * Return: the status of the program
 */
int lines_size(char *filename)
{
	FILE *file;
	char *line = NULL;
	ssize_t rstatus;
	size_t size = 0;
	int no_of_lines = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((rstatus = getline(&line, &size, file)) != -1)
	{
		no_of_lines++;
	}
	free(line);
	fclose(file);
	return (no_of_lines);
}
