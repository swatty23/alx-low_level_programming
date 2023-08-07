#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_error - Prints the error message and
 *               exits with the given code.
 * @msg: The error message to print.
 * @code: The exit code.
 */

void print_error(const char *msg, int code)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Entry point for the cp program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: Always 0 on success.
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
	print_error("Usage: cp file_from file_to", 97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
	print_error("Error: Can't read from file", 98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
	print_error("Error: Can't write to file", 99);
	}
	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
	bytes_written = write(fd_to, buffer, bytes_read);
	if (bytes_written == -1)
	{
	print_error("Error: Can't write to file", 99);
	}
	}
	if (bytes_read == -1)
	{
	print_error("Error: Can't read from file", 98);
	}
	if (close(fd_from) == -1)
	{
	print_error("Error: Can't close fd", 100);
	}
	if (close(fd_to) == -1)
	{
	print_error("Error: Can't close fd", 100);
	}
	return (0);
}
