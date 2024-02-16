#include "monty.h"
/**
 * pall - function that prints all the elements of a linked list.
 * @stack: Double linked list
 * @line_number: ignored variable
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp;

	if (stack == NULL)
	{
		return;
	}
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}
