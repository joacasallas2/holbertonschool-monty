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

	(void)line_number;

	new = malloc(sizeof(new));
	if (new == NULL)
	{
		return;
	}
	new->n = atoi(commands[1]);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}
