#include "monty.h"

void push(Stack_t **stack, unsigned int Line_num);
void pall(Stack_t **stack, unsigned int Line_num);
void pint(Stack_t **stack, unsigned int Line_num);
void pop(Stack_t **stack, unsigned int Line_num);
void swap(Stack_t **stack, unsigned int Line_num);



/**
 * pall - Display or Prints the values of a linked list with
 * the name Stack_t.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void pall(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_tmp_ = (*stack)->next;

	while (_tmp_)
	{
		printf("%d\n", _tmp_->n);
		_tmp_ = _tmp_->next;
	}
	(void)Line_num;
}

/**
 * pint - Display or Prints the top value of a linked list with
 * the name Stack_t.
 * @stack: pointer to the mode node at the top of a linked list stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void pint(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL)
	{
		Error_set_op_token(pint_error(Line_num));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}



/**
 * push - for Pushes a value to a linked list stack_t.
 * @stack: pointer to the mode node at the top of a linked list stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void push(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_tmp_, *_new;
	int j;

	_new = malloc(sizeof(Stack_t));
	if (_new == NULL)
	{
		Error_set_op_token(Erro_malloc());
		return;
	}

	if (Token_Opcode[1] == NULL)
	{
		Error_set_op_token(Error_NO_INT(Line_num));
		return;
	}

	for (j = 0; Token_Opcode[1][j]; j++)
	{
		if (Token_Opcode[1][j] == '-' && j == 0)
			continue;
		if (Token_Opcode[1][j] < '0' || Token_Opcode[1][j] > '9')
		{
			Error_set_op_token(Error_NO_INT(Line_num));
			return;
		}
	}
	_new->n = atoi(Token_Opcode[1]);

	if (mode_check(*stack) == STACK) /* STACK mode insert at front */
	{
		_tmp_ = (*stack)->next;
		_new->prev = *stack;
		_new->next = _tmp_;
		if (_tmp_)
			_tmp_->prev = _new;
		(*stack)->next = _new;
	}
	else /* QUEUE mode insert at end */
	{
		_tmp_ = *stack;
		while (_tmp_->next)
			_tmp_ = _tmp_->next;
		_new->prev = _tmp_;
		_new->next = NULL;
		_tmp_->next = _new;
	}
}


/**
 * pop -  it's used to remove the top value element from a linked list
 * using Stack_t.
 * @stack: pointer to the mode node at the top of a linked list stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void pop(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		Error_set_op_token(Error_pop(Line_num));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}


/**
 * swap - Changes the top two value elements of a linked list with
 * the name Stack_t.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 */
void swap(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_tmp_;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(Line_num, "swap"));
		return;
	}

	_tmp_ = (*stack)->next->next;
	(*stack)->next->next = _tmp_->next;
	(*stack)->next->prev = _tmp_;
	if (_tmp_->next)
		_tmp_->next->prev = (*stack)->next;
	_tmp_->next = (*stack)->next;
	_tmp_->prev = *stack;
	(*stack)->next = _tmp_;
}
