#include "monty.h"

/**
 * mod - mods the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}
	head = *stack;

	if (head->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		cleanup_and_exit();
	}

	sum = head->next->n % head->n;
	head->next->n = sum;
	*stack = head->next;
	free(head);
}

