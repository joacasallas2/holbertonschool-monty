#include "monty.h"
/**
 * push - adds a new node at the beginning of a linked list
 * @stack: Pointer to the linked list
 * @line_number: ignored variable
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int value;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return;
	}
	if (commands[1] == NULL)
	{
		dprintf(2, "L<%d>: usage: push integer\n", line_number);
		free_array(instructions);
		free_array(commands);
		free(new);
		exit(EXIT_FAILURE);
	}
	value = atoi(commands[1]);
	if (value == 0 && commands[1][0] != '0')
	{
		dprintf(2, "L<%d>: usage: push integer\n", line_number);
		free_array(instructions);
		free_array(commands);
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
