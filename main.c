#include "monty.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char **Token_Opcode = NULL;

/**
 * main - The Monty Interp entry point
 *
 * @argc:  The number of arguments passed to the program
 * @argv: a pointer to an array of char pointers to arguments
 *
 * Return:  If successful, return (EXIT_SUCCESS);
 * otherwise return (EXIT_FAILURE).
 *
 */

int main(int argc, char **argv)
{
	FILE *Fd_Script = NULL;
	int Code_EXIT = EXIT_SUCCESS;

	if (argc != 2)
		return (Error_utilisation());
	Fd_Script = fopen(argv[1], "r");
	if (Fd_Script == NULL)
		return (Error_Fopen(argv[1]));
	Code_EXIT = Monty_Execute(Fd_Script);
	fclose(Fd_Script);
	return (Code_EXIT);
}
