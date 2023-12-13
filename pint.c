#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack_t: stack header
 * @line_number: line number
 * Return: 0
*/

void pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack(*stack);
        cleanup_and_exit();
    }
    printf("%d\n", (*stack)->n);
}

void cleanup_and_exit()
{
    free(bus.file);
    free(bus.line);
    exit(EXIT_FAILURE);
}