#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack_t: stack header
 * @line_number: line number
 * Return: 0
*/

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    if (head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        cleanup_and_exit();
    }
    head = *stack;
    *stack = head->next;
    free(head)
}