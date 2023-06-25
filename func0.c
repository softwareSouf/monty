#include "monty.h"

char *filename;
FILE *file;
int push_arg;
char *buffer;
int flag_stack_queue = 0;

/**
 * main - Entry point.
 * @argc: number of arguments.
 * @argv: arguments.
 *
 * Description: main function for monty.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	int i = 1;
	while (i < argc) {
		if (argc != 2) {
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}
		filename = argv[i];
		rfile(filename, &stack);
		free_stack(stack);
		i++;
	}

	return (0);
}
