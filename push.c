#include "monty.h"

/**
 * f_push - add node to the stack
 * @new_node: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **stack, unsigned int value)
{
	/* Create a new node */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	
	/* Update the previous node's pointer */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack pointer to point to the new node */
	*stack = new_node;
}
