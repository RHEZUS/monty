#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int len = 0, sum = 0;

	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short,\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	sum = head->next->n - head->n;
	head->next->n = sum;
	*stack = head->next;
	free(head);
}
