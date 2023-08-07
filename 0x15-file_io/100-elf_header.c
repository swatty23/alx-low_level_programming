#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <elf.h>

#define BUF_SIZE 64

/**
 * print_error - Prints the error message and exits with the given code.
 * @msg: The error message to print.
 * @code: The exit code.
 */

void print_error(const char *msg, int code)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * display_elf_header - Displays the information contained in the ELF header
 * at the start of an ELF file.
 * @header: Pointer to the ELF header structure.
 */

void display_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
	printf("%02x ", header->e_ident[i])
	}
	printf("\n");
	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
	printf("ELF32\n");
	break;
	case ELFCLASS64:
	printf("ELF64\n");
	break;
	default:
	printf("Invalid\n");
	break;
	}
	printf("Data: ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
	printf("2's complement, little endian\n");
	break;
	case ELFDATA2MSB:
	printf("2's complement, big endian\n");
	break;
	default;
	printf("Invalid\n");
	break;
	}
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type: ");
	switch (header->e_type)
	{
	case ET_NONE:
	printf("NONE (Unknown type)\n");
	break;
	case ET_REL:
	printf("REL (Relocatable file)\n");
	break;
	case ET_EXEC:
	printf("EXEC (Executable file)\n");
	break;
	case ET_DYN:
	printf("DYN (Shared object file)\n");
	break;
	case ET_CORE:
	printf("CORE (Core file)\n");
	break;
	default:
	printf("Unknown\n");
	break;
	}
	printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * readelf - Reads an ELF file and displays its information.
 * @filename: The name of the ELF file to read.
 *
 * Displayed information: Magic, Class, Data, Version, OS/ABI, ABI Version, Type,
 * Entry point address (same format as readelf -h version 2.26.1).
 * If the file is not an ELF file or on error, exit with status code 98
 * and display a comprehensive error message to stderr.
 * You are allowed to use lseek once.
 * You are allowed to use read a maximum of 2 times at runtime.
 * You are allowed to have as many functions as you want in your source file.
 * You are allowed to use printf.
 * man elf, readelf for ELF file format details.
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	if (argc != 2)
	{
	print_error("Usage: elf_header elf_filename", 98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
	print_error("Error: Cannot open file", 98);
	}
	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr))
	{
	close(fd);
	print_error("Error: Cannot read ELF header", 98);
	}
	if (!(elf_header.e_ident[EI_MAG0] == ELFMAG0 &&
		elf_header.e_ident[EI_MAG1] == ELFMAG1 &&
		elf_header.e_ident[EI_MAG2] == ELFMAG2 &&
		elf_header.e_ident[EI_MAG3] == ELFMAG3))
	{
	close(fd);
	print_error("Error: Not an ELF file", 98);
	}
	display_elf_header(&elf_header);
	close(fd);
	return (0);
}

