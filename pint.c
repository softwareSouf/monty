#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}
