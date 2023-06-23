#include "monty.h"

/**
 * free_list_recursive - frees a list recursively.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_stack_recursive(stack_t *head)
{
	if (head == NULL)
		return;

	free_stack_recursive(head->next);
	free(head);
}

/**
 * free_list - frees a list.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	free_stack_recursive(head->next);
	free(head->prev);
	free(head);
}
