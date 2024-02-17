#include "monty.h"
/**
 * get_op_fun - Function that return the required function
 * @s: This is the format required
 * Return: A pointer to the function
 */
void (*get_op_fun(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"add", add},
	};
	int i;

	i = 0;
	while (i < 5)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
