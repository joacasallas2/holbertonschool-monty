#include "monty.h"
/**
 * free_list - function that frees a dlistint_t list.
 * @stack: The linked list to free
 * Return: Nothing (void function)
 */
void free_list(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}
