#include "monty.h"
/**
  *f_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
*/
void f_rotr(stack_t **head)
{
	stack_t *current = *head;
	stack_t *prev = NULL;
	
	if (current == NULL || current->next == NULL)
	{
		return;
	}
	
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	
	current->next = *head;
	prev->next = NULL;
	current->prev = NULL;
	(*head)->prev = current;
	*head = current;
}
