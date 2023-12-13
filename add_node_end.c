#include "monty.h"
/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_node_end(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *head = *stack;

	if (new_node == NULL)
	{
        fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
    }
	new_node->n = n;
	new_node->next = NULL;

	if ((*stack) == NULL)
	{
		new_node->prev = NULL;
		(*stack) = new_node;
	}

	while (head->next != NULL)
		head = head->next;

	head->next = new_node;
	new_node->prev = head;
}