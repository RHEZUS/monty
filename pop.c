#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack_t: stack header
 * @line_number: line number
 * Return: 0
*/

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;
    if (head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free_stack(*stack);
        cleanup_and_exit();
    }
    *stack = head->next;
    free(head);
}