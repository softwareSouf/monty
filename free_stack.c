#include "monty.h"

/**
 * free_stack_while - frees a list using while loop.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_stack_while(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		free_stack_while(current->next);
		free(current->prev);
		current = current->next;
	}
}
/**
 * free_stack - frees a list.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	free_stack_while(head->next);
	free(head->prev);
	free(head);
}
