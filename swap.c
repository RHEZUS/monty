#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int len = 0, swap = 0;

	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	swap = head->n;
	head->n = head->next->n;
	head->next->n = swap;
}

