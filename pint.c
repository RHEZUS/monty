#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}
	printf("%d\n", (*stack)->n);
}

/**
 * cleanup_and_exit - exits from the program
 */

void cleanup_and_exit(void)
{
	if (fclose(bus.file) != 0)
		fprintf(stderr, "Unable to close the file");

	if (bus.line != NULL)
		free(bus.line);

	exit(EXIT_FAILURE);
}
