#include "monty.h"

/**
 * pchar - prints the value at the top of the stack, followed by a new line.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = stack;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);

}

