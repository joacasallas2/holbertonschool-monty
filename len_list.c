#include "monty.h"
/**
 * len_list - function that returns the number of nodes in a linked list
 * @stack: The linked list
 * Return: the number of elements
 */
size_t len_list(stack_t **stack)
{
	size_t nodes = 0;

	printf("uno\n");

	while (*stack)
	{
		nodes++;
		*stack = (*stack)->next;
	}
	return (nodes);
}
