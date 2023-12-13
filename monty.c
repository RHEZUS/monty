#define _GNU_SOURCE
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: the files containing the command
 * Return: always 0
 */
int main(int argc, char const *argv[])
{

	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	ssize_t read;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr,  "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bus.file = file;

	while ((read = getline(&line, &len, file)) != -1)
	{
		counter++;
		line = handle_comment(line);
		bus.line = line;
		execute(line, &stack, counter);
	}

	if (fclose(file) != 0)
	{
		fprintf(stderr, "Error: Failed to close the file.\n");
		free_stack(stack);
		cleanup_and_exit();
	}
	return (0);
}

