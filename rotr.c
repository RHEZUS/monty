#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack header
 * @line_number: line number
 * Return: 0
 */

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *cpy_stack;

    cpy_stack = *stack;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }
    while (cpy_stack->next)
    {
        cpy_stack = cpy_stack->next;
    }
    cpy_stack->next = *stack;

    cpy_stack->prev->next = NULL;
    cpy_stack->prev = NULL;
    (*stack)->prev = cpy_stack;

    (*stack) = copy;
}