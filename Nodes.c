#include "monty.h"
/**
 * create_node - Creates a node.
 * @n: num of nodes.
 * Return: return node.
 */
stack_t *create_node(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		Error_Handle(4);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = n;
	return (newNode);
}
/**
 * freeNodes - Frees nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *ptr;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}
/**
 * add_to_queue - add new queue.
 * @new_node: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *new_node;
	(*new_node)->prev = ptr;

}
