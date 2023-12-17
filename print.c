#include "monty.h"
/**
 * print_all_func - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void print_all_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * print_top_func - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void print_top_func(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * print_char_func - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void print_char_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * print_str_func - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void print_str_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * pop_func - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
