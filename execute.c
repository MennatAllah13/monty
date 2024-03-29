#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_func}, {"pall", print_all_func}, {"pint", print_top_func},
				{"pop", pop_func},
				{"swap", swap_func},
				{"add", add_func},
				{"nop", no_func},
				{"sub", sub_func},
				{"div", div_func},
				{"mul", mult_func},
				{"mod", mod_func},
				{"pchar", print_char_func},
				{"pstr", print_str_func},
				{"rotl", rotl_func},
				{"rotr", rotr_func},
				{"queue", queue_func},
				{"stack", stack_func},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		stack_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
  *no_func- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void no_func(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
