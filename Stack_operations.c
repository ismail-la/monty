#include "monty.h"
#include <string.h>a

void Stack_free(Stack_t **stack);
int Stack_init(Stack_t **stack);
int mode_check(Stack_t *stack);



/**
 * Stack_init - Initializes a stack_t stack with * stack and queue nodes
 * at the beginning and end.
 * @stack: Pointer to a stack_t unitialized stack.
 *
 * Return: If no error occurs - EXIT_SUCCESS.
 *         Otherwise - EXIT_FAILURE.
 */
int Stack_init(Stack_t **stack)
{
	Stack_t *st;

	st = malloc(sizeof(Stack_t));
	if (st == NULL)
		return (Erro_malloc());

	st->n = STACK;
	st->prev = NULL;
	st->next = NULL;

	*stack = st;

	return (EXIT_SUCCESS);
}



/**
 * Stack_free - Release a stack Stack_t
 * @stack: a pointer to a Stack_t's top (stack) or * bottom (queue) level.
 *
 */
void Stack_free(Stack_t **stack)
{
	Stack_t *_tmp_ = *stack;

	while (*stack)
	{
		_tmp_ = (*stack)->next;
		free(*stack);
		*stack = _tmp_;
	}
}

/**
 * mode_check -  Determines whether a linked Stack_t list is operating
 * in queue or stack mode.
 * @stack: a pointer to a linked Stack_t list's top (stack) or bottom (queue).
 *
 * Return: STACK (0) If the Stack_t is in stack mode -
 * QUEUE (1) If the Stack_t is in queue mode -
 * Otherwise - 2.
 */
int mode_check(Stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
