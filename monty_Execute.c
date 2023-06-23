#define  _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <string.h>

void Tokens_rm_str(void);
unsigned int Token_len_get(void);
int Line_is_empty(char *_Line, char *delimeter);
void (*get_func_OPcode(char *_Opcode))(Stack_t**, unsigned int);
int Monty_Execute(FILE *script_fd);

/**
 * Tokens_rm_str - removes the strings from the global Token_Opcode array.
 */
void Tokens_rm_str(void)
{
	size_t x = 0;

	if (Token_Opcode == NULL)
		return;

	for (x = 0; Token_Opcode[x]; x++)
		free(Token_Opcode[x]);

	free(Token_Opcode);
}

/**
 * Token_len_get - Determines the current Token_Opcode's length.
 *
 * Return:  The current length of the Token_Opcode (int).
 */
unsigned int Token_len_get(void)
{
	unsigned int toks_len = 0;

	while (Token_Opcode[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * Line_is_empty - Determines whether a line read from getline contains
 * only delimiters.
 * @_Line: _Line pointer.
 * @delimeter: A line string of delimiter characters.
 * Return:  If there are only delimiters on the line: - 1.
 * Otherwise - 0.
 */
int Line_is_empty(char *_Line, char *delimeter)
{
	int x, j;

	for (x = 0; _Line[x]; x++)
	{
		for (j = 0; delimeter[j]; j++)
		{
			if (_Line[x] == delimeter[j])
				break;
		}
		if (delimeter[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * get_func_OPcode -  Gets an opcode and the function it corresponds to.
 * @_Opcode:  the appropriate opcode.
 *
 * Return: a pointer to the function that corresponds to it.
 */
void (*get_func_OPcode(char *_Opcode))(Stack_t**, unsigned int)
{
	instruction_t funcs_op[] = {
		{"mul", mul},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", mrotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int x;

	for (x = 0; funcs_op[x]. opcode; x++)
	{
		if (strcmp(_Opcode, funcs_op[x]. opcode) == 0)
			return (funcs_op[x].f);
	}

	return (NULL);
}

/**
 * Monty_Execute - this is thePrimary function to execute
 *(Monty bytecodes script).
 * @script_fd: THE FD File descriptor for an open (Monty bytecodes script).
 * Return: EXIT_SUCCESS on success, the appropriate error code on fail.
 */
int Monty_Execute(FILE *script_fd)
{
	unsigned int prev_tok_len = 0, Line_num = 0;
	Stack_t *stack = NULL;
	size_t exit_status = EXIT_SUCCESS, len = 0;
	char *line = NULL;
	void (*op_func)(Stack_t**, unsigned int);

	if (Stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		Line_num++;
		Token_Opcode = _strtow(line, DELIMS);
		if (Token_Opcode == NULL)
		{
			if (Line_is_empty(line, DELIMS))
				continue;
			Stack_free(&stack);
			return (Erro_malloc());
		}
		else if (Token_Opcode[0][0] == '#') /* comment line */
		{
			Tokens_rm_str();
			continue;
		}
		op_func = get_func_OPcode(Token_Opcode[0]);
		if (op_func == NULL)
		{
			Stack_free(&stack);
			exit_status = Error_unknown_OP(Token_Opcode[0], Line_num);
			Tokens_rm_str();
			break;
		}
		prev_tok_len = Token_len_get();
		op_func(&stack, Line_num);
		if (Token_len_get() != prev_tok_len)
		{
			if (Token_Opcode && Token_Opcode[prev_tok_len])
				exit_status = atoi(Token_Opcode[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			Tokens_rm_str();
			break;
		}
		Tokens_rm_str();
	}
	Stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (Erro_malloc());
	}
	free(line);
	return (exit_status);
}
