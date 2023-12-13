#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	UNUSED(line_number);
	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}

