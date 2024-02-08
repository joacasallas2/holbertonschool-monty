#include "monty.h"
/**
 * tokenizer - function that splits a string and returns an array
 * of each word of the string
 * @line_ptr: The string to tokenizer
 * @delim: The characters to use as delim
 * Return: A pointer to the array of strings splitted
 */
char **tokenizer(char *line_ptr, char *delim)
{
	char *token, *line_ptr_copy;
	char **buffer;
	int i = 0, j = 0;

	/*Allocates memory*/
	buffer = malloc(sizeof(char *) * 1024);
	if (buffer == NULL)
	{
		free(line_ptr);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* split the input line into tokens.*/
	line_ptr_copy = strdup(line_ptr);
	if (line_ptr_copy == NULL)
	{
		free(line_ptr);
		free(buffer);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_ptr_copy, delim);
	while (token != NULL)
	{
		/*Allocates memory for each token using strdup.*/
		buffer[i] = strdup(token);
		if (buffer[i] == NULL)
		{
			while (j < i)
			{
				free(buffer[j]);
				j++;
			}
			free(buffer);
			free(line_ptr);
			dprintf(2, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}
	buffer[i] = NULL;
	free(line_ptr_copy);
	return (buffer);
}
