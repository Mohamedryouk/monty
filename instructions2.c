#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}
/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *ptr;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "swap");
        ptr = (*stack)->next;
        (*stack)->next = ptr->next;
        if (ptr->next != NULL)
                ptr->next->prev = *stack;
        ptr->next = *stack;
        (*stack)->prev = ptr;
        ptr->prev = NULL;
        *stack = ptr;
}
/**
 * add_nodes - add node to stack or queue.
 * @stack: Pointer to a pointer.
 * @line_number: lines number.
 */
void addNodes(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "add");

        (*stack) = (*stack)->next;
        sum = (*stack)->n + (*stack)->prev->n;
        (*stack)->n = sum;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}
/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void subNodes(stack_t **stack, unsigned int line_number)
{
        int allstack;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

                more_err(8, line_number, "sub");


        (*stack) = (*stack)->next;
        allstack = (*stack)->n - (*stack)->prev->n;
        (*stack)->n = allstack;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}
/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void dvNodes(stack_t **stack, unsigned int line_number)
{
        int nnum;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "div");

        if ((*stack)->n == 0)
                more_err(9, line_number);
        (*stack) = (*stack)->next;
        nnum = (*stack)->n / (*stack)->prev->n;
        (*stack)->n = nnum;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}