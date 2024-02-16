#include "monty.h"
char **commands;
char **instructions;
stack_t **stack;
unsigned int line_number;
/**
 * main - entry point to the monty program
 * @argc: The number of args
 * @argv: The pointer to the array of args
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *filename = NULL;
	char *line_ptr = NULL;
	int i = 0;
	void (*function_ptr)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
	{
		dprintf(2, "Empty file\n");
		return (0);
	}
	filename = argv[1];
	line_ptr = read_textfile(filename, BUFFER_SIZE);
	if (line_ptr == NULL)
	{
		dprintf(2, "Empty file\n");
		return (0);
	}
	instructions = tokenizer(line_ptr, "\n");
	free(line_ptr);
	if (instructions == NULL)
	{
		dprintf(2, "error tokenizing line_ptr\n");
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t *));
	if (stack == NULL)
	{
		dprintf(2, "error malloc stack\n");
		free_array(instructions);
		return EXIT_FAILURE;
	}
	while (instructions[i])
	{
		line_number = i;
		commands = tokenizer(instructions[i], " ");
		if (commands == NULL)
		{
			free_array(instructions);
			dprintf(2, "error tokenizing instructions[%d]\n", i);
			exit(EXIT_FAILURE);
		}
		function_ptr = get_op_fun(commands[0]);
		if (function_ptr == NULL)
		{
			dprintf(2, "L<%d>: unknown instruction <%s>\n", i, commands[0]);
			free_array(instructions);
			free_array(commands);
			exit(EXIT_FAILURE);
		}
		function_ptr(stack, i);
		free_array(commands);
		i++;
	}
	free_array(instructions);
	free_list(stack);
	return (0);
}
