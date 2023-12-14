#include "monty.h"

/**
 * pstr - prints all the values in the stack in Ascii.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	UNUSED(line_number);
	head = *stack;
	if (head == NULL)
		return;

	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	putchar('\n');
}
