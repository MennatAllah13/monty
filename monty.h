#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct s_bus - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct s_bus
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  t_bus;
extern t_bus bus;

void push_func(stack_t **head, unsigned int number);
void print_all_func(stack_t **head, unsigned int number);
void print_top_func(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void stack_free(stack_t *head);
void pop_func(stack_t **head, unsigned int counter);
void swap_func(stack_t **head, unsigned int counter);
void add_func(stack_t **head, unsigned int counter);
void nop_func(stack_t **head, unsigned int counter);
void sub_func(stack_t **head, unsigned int counter);
void div_func(stack_t **head, unsigned int counter);
void mult_func(stack_t **head, unsigned int counter);
void mod_func(stack_t **head, unsigned int counter);
void print_char_func(stack_t **head, unsigned int counter);
void print_str_func(stack_t **head, unsigned int counter);
void rotl_func(stack_t **head, unsigned int counter);
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int counter);
void node_add(stack_t **head, int n);
void queue_add(stack_t **head, int n);
void queue_func(stack_t **head, unsigned int counter);
void stack_func(stack_t **head, unsigned int counter);

#endif
