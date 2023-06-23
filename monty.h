#ifndef _MONTY_
#define _MONTY_
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define DELIMS " \n\t\a\b"
#define QUEUE 1
#define STACK 0
/** THe GLOBAL OPCODE TOKENS **/
extern char **Token_Opcode;
/**
 * struct stack_s - representation of a doubly linked list of a queue
 * or a stack
 * @n: integer
 * @prev: points to the previous queue or stack element.
 * @next: points to the next queue or stack element.
 * Description: structure of doubly linked list node
 *for LIFO, FIFO, Stack, Queue
 * ALX project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} Stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: the opcode and its function for LIFO, FIFO, Stack, Queue
 * ALX project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(Stack_t **stack, unsigned int line_number);
} instruction_t;
/** THE OPCODE FUNCTIONS **/
void push(Stack_t **stack, unsigned int line_number);
void pall(Stack_t **stack, unsigned int line_number);
void pint(Stack_t **stack, unsigned int line_number);
void pop(Stack_t **stack, unsigned int line_number);
void swap(Stack_t **stack, unsigned int line_number);
void add(Stack_t **stack, unsigned int line_number);
void nop(Stack_t **stack, unsigned int line_number);
void sub(Stack_t **stack, unsigned int line_number);
void monty_div(Stack_t **stack, unsigned int line_number);
void mul(Stack_t **stack, unsigned int line_number);
void mod(Stack_t **stack, unsigned int line_number);
void pchar(Stack_t **stack, unsigned int line_number);
void pstr(Stack_t **stack, unsigned int line_number);
void mrotl(Stack_t **stack, unsigned int line_number);
void rotr(Stack_t **stack, unsigned int line_number);
void stack(Stack_t **stack, unsigned int line_number);
void queue(Stack_t **stack, unsigned int line_number);
/** THE PRIMARY INTERPRETER FUNCTIONS**/
void Stack_free(Stack_t **stack);
int Stack_init(Stack_t **stack);
int mode_check(Stack_t *stack);
void Tokens_rm_str(void);
unsigned int Token_len_get(void);
int Monty_Execute(FILE *script_fd);
void Error_set_op_token(int error_code);
/** ERROR CODES and ERROR MESSAGES **/
int Error_utilisation(void);
int Erro_malloc(void);
int Error_Fopen(char *filename);
int Error_unknown_OP(char *opcode, unsigned int line_number);
int Error_NO_INT(unsigned int line_number);
int Error_pop(unsigned int line_number);
int pint_error(unsigned int line_number);
int Error_short_Stack(unsigned int line_number, char *op);
int Error_Div(unsigned int line_number);
int Error_Pchar(unsigned int line_number, char *message);
/** THE CUSTOM STANDARD LIBRARY FUNCTIONS **/
char **_strtow(char *str, char *delims);
char *gets_integer(int n);
#endif
