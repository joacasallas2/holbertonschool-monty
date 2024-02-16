#include "monty.h"
/**
 * pint - function that prints the value at the top of the stack
 * @stack: Double linked list
 * @line_number: ignored variable
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*while (temp->next)
	{
		temp = temp->next;
	}*/
	printf("%d\n", temp->n);
}
