#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
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
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        free_stack(*stack);
        cleanup_and_exit();
    }
    head = *stack;
    sum = head->n + head->next->n;
    head->next->n = sum;
    *stack = head->next;
    free(head); 
}