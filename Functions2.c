#include "monty.h"

void add(Stack_t **stack, unsigned int Line_num);
void sub(Stack_t **stack, unsigned int Line_num);
void monty_div(Stack_t **stack, unsigned int Line_num);
void mul(Stack_t **stack, unsigned int Line_num);
void mod(Stack_t **stack, unsigned int Line_num);

/**
 * add - Adds the top two values of a Stack_t linked list.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 * Description: The top value is removed and the result is stored in
 * the second value node from the top.
 */
void add(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(Line_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, Line_num);
}

/**
 * sub - subtracts the top value from the second value in
 * a linked Stack_t list.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 * Description: The top value is removed and the result is stored in
 * the second value node from the top.
 */
void sub(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(Line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, Line_num);
}

/**
 * monty_div - divides the top value by the second value in
 * a linked Stack_t list.
 * @stack: pointer to the mode node at the top of a linked list t_Stack.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 * Description: The top value is removed and the result is stored in
 * the second value node from the top.
 */
void monty_div(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(Line_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		Error_set_op_token(Error_Div(Line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, Line_num);
}

/**
 * mul - for Multiplies the second value from the top by the top value.
 * of a Stack_t linked list
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 * Description: The top value is removed and the result is stored in
 * the second value node from the top.
 */
void mul(Stack_t **stack, unsigned int Line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(Line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, Line_num);
}

/**
 * mod - Processes the modulus of the second worth from the highest
 * point of a t_Stack connected list by the top worth.
 * @stack: pointer to the mode node at the top of a linked list t_Stack.
 * @line_number: the number of a Monty bytecodes file's current working line.
 *
 * Description: The top value is removed and the result is stored in
 * the second value node from the top.
 */
void mod(Stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		Error_set_op_token(Error_short_Stack(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		Error_set_op_token(Error_Div(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
