#include "monty.h"

/**
 * split_line - splits line to opcode and argument.
 * @line: the line to be splitted.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: opcode ot NULL if it fails.
 */
char *fr_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *push = "push", *opcode, *arg;
	(void)stack;

	opcode = strtok(line, " ");
	if (opcode == NULL)
		return (NULL);
	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, " ");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
		if (!isdigit(arg[0]) && arg[0] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}

/**
 * is_number - checks if a string if is a number.
 * @st: the string to be checked.
 *
 * Return: 0 if it is a number,
 * otherwise 1.
 */
int is_number(char *st)
{
	int i;

	if (st == NULL)
		return (1);
	for (i = 0; st[i]; i++)
	{
		if (st[0] == '-')
		{
			if (i == 1)
				continue;
			else
				return (1);
		}
		if (!isdigit(st[i]))
			return (1);
	}
	return (0);
}
