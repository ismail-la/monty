#include "monty.h"

void mrotl(Stack_t **stack, unsigned int Line_num);
void rotr(Stack_t **stack, unsigned int Line_num);
void stack(Stack_t **stack, unsigned int Line_num);
void queue(Stack_t **stack, unsigned int Line_num);



/**
 * rotr - moves or rotates the value at the _bottom of a linked Stack_t*
 * list to the _top.
 * @stack: pointer to the mode node at the _top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 */
void rotr(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_top, *_bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	_top = (*stack)->next;
	_bottom = (*stack)->next;
	while (_bottom->next != NULL)
		_bottom = _bottom->next;

	_bottom->prev->next = NULL;
	(*stack)->next = _bottom;
	_bottom->prev = *stack;
	_bottom->next = _top;
	_top->prev = _bottom;

	(void)Line_num;
}



/**
 * queue - Transforms or convert a stack into a queue.
 * @stack: pointer to the mode node at the top of a linked list t_Stack.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 */
void queue(Stack_t **stack, unsigned int Line_num)
{
	(*stack)->n = QUEUE;
	(void)Line_num;
}

/**
 * mrotl - Moves or rotates the value at the top of a linked Stack_t list
 * to the _bottom.
 * @stack: pointer to the mode node at the top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 */
void mrotl(Stack_t **stack, unsigned int Line_num)
{
	Stack_t *_top, *_bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	_top = (*stack)->next;
	_bottom = (*stack)->next;
	while (_bottom->next != NULL)
		_bottom = _bottom->next;

	_top->next->prev = *stack;
	(*stack)->next = _top->next;
	_bottom->next = _top;
	_top->next = NULL;
	_top->prev = _bottom;

	(void)Line_num;
}

/**
 * stack -  Transforms or convert a queue into a stack.
 * @stack: pointer to the mode node at the _top of a linked list Stack_t.
 * @Line_num: the number of a Monty bytecodes file's current working line.
 *
 */
void stack(Stack_t **stack, unsigned int Line_num)
{
	(*stack)->n = STACK;
	(void)Line_num;
}
