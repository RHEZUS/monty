#include "monty.h"

/**
 * _div - divs the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int length = 0, result;
	stack_t *current = *stack;
	
	while (current)
	{
		current = current->next;
		length++;
	}
	
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n % current->n;
	current->next->n = result;

	*stack = current->next;
	free(current);
}

