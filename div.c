#include "monty.h"

/**
 * _div - divs the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int len = 0, result;

	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = head->next->n % head->n;
	head->next->n = result;
	*stack = head->next;
	free(head);
}

