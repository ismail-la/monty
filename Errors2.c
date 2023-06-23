#include "monty.h"

int Error_short_Stack(unsigned int Line_num, char *op);

int Error_Div(unsigned int Line_num);

int Error_pop(unsigned int Line_num);

int Error_Div(unsigned int Line_num);

int Error_Pchar(unsigned int Line_num, char *msg);

/**
 * Error_Pchar - Display or Prints pchar error messages for empty stacks
 * and non-character values.
 * @Line_num: the script's line number where the error occurred.
 * @msg: The appropriate print error message
 * Return: (EXIT_FAILURE) always.
 */
int Error_Pchar(unsigned int Line_num, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", Line_num, msg);
	return (EXIT_FAILURE);
}

/**
 * pint_error - For empty stacks, prints pint error messages.
 * @Line_num: the script's line number where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int Line_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", Line_num);
	return (EXIT_FAILURE);
}

/**
 * Error_Div - Displays division error messages when divided by 0.
 * @Line_num: the script's line number where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int Error_Div(unsigned int Line_num)
{
	fprintf(stderr, "L%u: division by zero\n", Line_num);
	return (EXIT_FAILURE);
}

/**
 * Error_pop - to Prints pop error messages for empty stacks.
 * @Line_num:  the script's line number where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int Error_pop(unsigned int Line_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", Line_num);
	return (EXIT_FAILURE);
}

/**
 * Error_short_Stack - For stacks or queues with fewer than two nodes,
 * this function prints error messages for the Monte Carlo math function.
 * @Line_num: the script's line number where the error occurred.
 * @op: the Operation where the error occurred or was made.
 * Return: (EXIT_FAILURE) always.
 */
int Error_short_Stack(unsigned int Line_num, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", Line_num, op);
	return (EXIT_FAILURE);
}
