#include "monty.h"
/**
 * pop - function that removes the top element of the stack.
 * @stack: Double linked list
 * @line_number: ignored variable
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp == *stack)
	{
		*stack = temp->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}
	}
	free(temp);
}
