#include "monty.h"
/**
 * pall - function that prints all the elements of a linked list.
 * @stack: Double linked list
 * Return: The number of nodes
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
		i++;
	}
}
