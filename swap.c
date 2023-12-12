#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *h = *stack;
    int len = 0, temp;

    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short", line_number);
        cleanup_and_exit();
    }

    h = *stack;
    temp = h->n;
    h->n = h->next->n;
    h->next->n = temp;
}