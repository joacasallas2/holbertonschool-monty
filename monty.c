#include "monty.h"
char **commands;
stack_t **stack;
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
	char **instructions;
	int i = 0;
	void (*function_ptr)(stack_t **stack, unsigned int line_number);

	stack = malloc(sizeof(stack_t) * BUFFER_SIZE);

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
	while (instructions[i])
	{
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
	return (0);
}
