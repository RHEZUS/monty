#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack, *head;

    UNUSED(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	head = (*stack)->next;
	head->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = head;
}