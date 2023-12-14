#include "monty.h"

/**
 * pstr - prints all the values in the stack in Ascii.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	UNUSED(line_number);
	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
