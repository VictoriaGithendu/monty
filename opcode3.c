#include "monty.h"
/**
 * _rotl - function  that rotates the first element
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux1 = (*doubly)->next;
	aux2 = *doubly;
	for (; aux2->next != NULL; aux2 = aux2->next)
		;
	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}
/**
 * _rotr - function that reverses the stack
 * @doubly: linked list head
 * @cline: line number
 * Return: no return
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux = *doubly;
	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
