#include "monty.h"
/**
 * read_textfile - function that reads a text file.
 * @filename: The text file
 * @letters: The number of letters it should read
 * * Return: A pointer to the buffer with the textfile readed
 * if file is NULL or if it fails return 0.
 */
char *read_textfile(const char *filename, size_t letters)
{
	int fd;
	size_t readed;
	char *line_ptr;

	if (filename == NULL || letters == 0)
	{
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		dprintf(2, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}
	line_ptr = malloc(sizeof(char *) * letters + 1);
	if (line_ptr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	readed = read(fd, line_ptr, letters + 1);
	line_ptr[readed] = '\0';
	if (readed == 0)
	{
		free(line_ptr);
		dprintf(2, "Error: Can't read the file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (line_ptr);
}
