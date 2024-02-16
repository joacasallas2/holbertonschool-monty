#include "monty.h"
/**
 * free_list - function that frees a dlistint_t list.
 * @head: The linked list to free
 * Return: Nothing (void function)
 */
void free_list(stack_t **stack)
{
	stack_t *temp;
	int i = 0;

	if (stack == NULL && *stack == NULL)
	{
		return;
	}
	while (i < 3)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		i++;
	}
	free(stack);
}
