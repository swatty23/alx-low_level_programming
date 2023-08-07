#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to
 *                add at the end of the file.
 * Return: 1 on success, -1 on failure.
 *         Do not create the file if it does not exist.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, do not add anything to the file.
 *         Return 1 if the file exists and -1 if the file does not exist
 *         or if you do not have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result;
	size_t text_length = 0;

	if (filename == NULL)
	return (-1);
	if (text_content == NULL)
	return (1);
	while (text_content[text_length] != '\0')
	text_length++;
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);
	write_result = write(fd, text_content, text_length);
	close(fd);
	if (write_result == -1)
	return (-1);
	return (1);
}
