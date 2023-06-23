#include "monty.h"

void nop(Stack_t **stack, unsigned int Line_num);
void pchar(Stack_t **stack, unsigned int Line_num);
void pstr(Stack_t **stack, unsigned int Line_num);



/**
 * pchar - Display or Prints the character in the Stack_t linked list's
 * top value node.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void pchar(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL)
	{
		Error_set_op_token(Error_Pchar(Line_num, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		Error_set_op_token(Error_Pchar(Line_num,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}



/**
 * nop - has no effect at all on the Monty opcode "nop."
 * @stack: pointer to the mode node at the top of a linked list stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void nop(Stack_t **stack, unsigned int Line_num)
{
	(void)stack;
	(void)Line_num;
}

/**
 * pstr - Display or Prints the string in a linked list with
 * the name Stack_t.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void pstr(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_tmp_ = (*stack)->next;

	while (_tmp_ && _tmp_->n != 0 && (_tmp_->n > 0 && _tmp_->n <= 127))
	{
		printf("%c", _tmp_->n);
		_tmp_ = _tmp_->next;
	}
	printf("\n");
	(void)Line_num;
}
