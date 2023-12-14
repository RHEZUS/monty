#include "monty.h"

/**
 * _stack - change the the insertion mode to stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.status = STACK;
}

