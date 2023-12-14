#include "monty.h"

/**
 * pchar - prints the value at the top of the stack, followed by a new line.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);

}

