#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void rotl(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }
    stack_t *new_stack = (*stack)->next
    new_stack->prev = NULL:

    stack_t *head = *stack;
    while (head->next != null)
    {
        head = head->next
    }
    head->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = head;

    *stack = new_stack;
}