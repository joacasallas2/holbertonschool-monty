#include "monty.h"
/**
 * sub - function that subtracts the top element of the stack from the second
 * top element of the stack.
 * @stack: Double linked list
 * @line_number: ignored variable
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;
	int res = 0;

	if (*stack == NULL || len_list(stack) < 2)
	{
		dprintf(2, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = temp->next->n - temp->n;
	*stack = temp->next;
	free(temp);
	(*stack)->n = res;
}
