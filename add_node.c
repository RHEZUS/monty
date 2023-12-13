#include "monty.h"
/**
 * add_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_node(stack_t **stack, int n)
{

	stack_t *new_node = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	/*
	stack_t *new_node, *h;

	h = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (h)
		h->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;*/
}

