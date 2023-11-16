#include "monty.h"
/**
 * _queue - function that sets the data format to a queue (FIFO)
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}
/**
 * _stack - function that sets the data format to a stack (LIFO)
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}
/**
 * _add - function that adds the top two elements of the stack
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;
	if (x < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _nop - function that doesn't do anythinhg
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
/**
 * _sub - function that subtracts the top element
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;
	if (x < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
