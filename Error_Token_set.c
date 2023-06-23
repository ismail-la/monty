#include "monty.h"

/**
 * Error_set_op_token - Specifies an error code for the last element of
 * Token_Opcode.
 * @Code_error: a number integer that will be saved as a string in
 * Token_Opcode.
 */
void Error_set_op_token(int Code_error)
{
	char *str_exit = NULL;
	char **tok_new = NULL;
	int Len_tok = 0;
	int j = 0;

	Len_tok = Token_len_get();

	tok_new = malloc(sizeof(char *) * (Len_tok + 2));
	if (!Token_Opcode)
	{
		Erro_malloc();
		return;
	}
	while (j < Len_tok)
	{
		tok_new[j] = Token_Opcode[j];
		j++;
	}
	str_exit = gets_integer(Code_error);
	if (!str_exit)
	{
		free(tok_new);
		Erro_malloc();
		return;
	}
	tok_new[j++] = str_exit;
	tok_new[j] = NULL;
	free(Token_Opcode);
	Token_Opcode = tok_new;
}
