#include "monty.h"

int Error_utilisation(void);

int Erro_malloc(void);

int Error_Fopen(char *Name_File);

int Error_unknown_OP(char *OP_CODE, unsigned int Line_num);

int Error_NO_INT(unsigned int Line_num);


/**
 * Error_NO_INT -  Prints messages indicating
 * that the push argument is invalid.
 * @Line_num:  The Monty bytecodes file's line number
 * where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int Error_NO_INT(unsigned int Line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", Line_num);
	return (EXIT_FAILURE);
}

/**
 * Error_unknown_OP - Prints error messages for unknown instructions.
 * @OP_CODE: Opcode the location of the error.
 * @Line_num:  the error's line number in the Monty bytecodes file.
 * Return: (EXIT_FAILURE) always.
 */
int Error_unknown_OP(char *OP_CODE, unsigned int Line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		Line_num, OP_CODE);
	return (EXIT_FAILURE);
}

/**
 * Erro_malloc - Prints error messages for malloc.
 *
 * Return: (EXIT_FAILURE) always.
 */
int Erro_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * Error_Fopen - Prints file opening error messages w/ file name.
 * @Name_File: Name of the file that could not be opened
 * Return: (EXIT_FAILURE) always.
 */
int Error_Fopen(char *Name_File)
{
	fprintf(stderr, "Error: Can't open file %s\n", Name_File);
	return (EXIT_FAILURE);
}

/**
 * Error_utilisation - Prints messages about usage errors.
 * Return: (EXIT_FAILURE) always.
 */
int Error_utilisation(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
