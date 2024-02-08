#include "monty.h"
/**
 * pall - function that prints all the elements of a linked list.
 * @stack: Double linked list
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
		i++;
	}
}
