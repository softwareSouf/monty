#include "monty.h"
/**
* main - monty code interpreter
* @head: number of arguments
* @getline - monty file location
* Return: 0 on success
*/
int main(void)
{
	stack_t *head = NULL;
	char *line = NULL;
	unsigned int line_number = 1;
	
	while (getline(&line, 1024, stdin) != -1)
	{
		line = clean_line(line);
		if (line[0] == '\0')
			continue;
		char *opcode = strtok(line, " ");
		instruction_t *instruction = get_instruction(opcode);
		
		if (instruction == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		
		instruction->f(&head, line_number);
		line_number++;
	}
	
	free_stack(head);
	free(line);

	return 0;
}
