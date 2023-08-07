#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "main.h"

/**
 * create_file - Creates a file with the specified text content.
 * @filename: The name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 * Return: 1 on success, -1 on failure (file cannot be created,
 *         file cannot be written, write "fails", etc...)
 *         The created file must have those permissions: rw-------.
 *         If the file already exists, do not change the permissions.
 *         If the file already exists, truncate it.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_result;
	mode_t permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
	return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (fd == -1)
	return (-1);
	if (text_content != NULL)
	{
	size_t text_length = 0;

	while (text_content[text_length] != '\0')
	text_length++;
	write_result = write(fd, text_content, text_length);
	if (write_result == -1)
	{
	close(fd);
	return (-1);
	}
	}
	close(fd);
	return (1);
}
