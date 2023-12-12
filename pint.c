#include "monty.h"

/**
 * pint - prints all the values on the stack, starting from the top of the stack.
 * @stack_t: stack header
 * @line_number: line number
 * Return: 0
*/

void pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
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