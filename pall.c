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
	stack_t *temp = *stack;
	int i = 0;

	if (stack == NULL && *stack == NULL)
	{
		return;
	}
	while (i < 3)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		i++;
	}
}
