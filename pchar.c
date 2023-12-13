#include "monty.h"

/**
 * pchar - prints the value at the top of the stack, followed by a new line.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		free(bus.line);
        free(bus.file);
        exit(EXIT_FAILURE);
	}
	if ((*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		free(bus.line);
        free(bus.file);
        exit(EXIT_FAILURE);
	}

}

