#include "monty.h"

/**
 * sub - subd the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
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
		cleanup_and_exit();
	}
	head = *stack;
	sum = head->next->n - head->n;
	head->next->n = sum;
	*stack = head->next;
	free(head);
}
