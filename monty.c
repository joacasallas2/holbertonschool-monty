#include "monty.h"
char **commands;
/**
 * main - entry point to the monty program
 * @argc: The number of args
 * @argv: The pointer to the array of args
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *filename;
	char *line_ptr;
	char **instructions;
	int i;
	void (*function_ptr)(stack_t **stack, unsigned int line_number);
	stack_t **stack = NULL;

	(void)stack;

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
	line_ptr = read_textfile(filename, strlen(filename));
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
		return (0);
	}
	while (instructions[i])
	{
		commands = tokenizer(instructions[i], " ");
		free(instructions[i]);
		if (commands == NULL)
		{
			dprintf(2, "error tokenizing instructions[%d]\n", i);
			continue;
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
