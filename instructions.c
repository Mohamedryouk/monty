#include "monty.h"
/**
 * push_to_stack - push a node to the stack.
 * @new_node: Pointer to the newNode.
 * @line_number: Interger representing the line number of of the opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
		head = *new_node;
	ptr = head;
	head = *new_node;
	head->next = ptr;
	ptr->prev = head;
}


/**
 * pall_the_stack - push a newNode.
 * @stack: Pointer to node of the stack.
 * @line_number: line number of  the opcode.
 */
void pall_the_stack(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *pointer;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	pointer = *stack;
	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}

/**
 * pop_top - pop a node.
 * @stack: Pointer to a pointer.
 * @line_number: line_number integer.
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *ptr;

        if (stack == NULL || *stack == NULL)
                more_err(7, line_number);

        ptr = *stack;
        *stack = ptr->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(ptr);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_print(stack_t **stack, unsigned int line_number)
{
        if (stack == NULL || *stack == NULL)
                	more_err(6, line_number);
		printf("%d\n", (*stack)->n);
}