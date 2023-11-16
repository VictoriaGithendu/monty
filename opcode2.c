#include "monty.h"
/**
 * _div - function that divides the stack second element by the top one
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _div(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;
	if (x < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _mul - function that multiplies the stack top element to second element
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _mul(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _mod - function that computes the division of the second element
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pchar - function that prints the first element char value
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - function that prints the stack string
 * @doubly: linked list head
 * @cline: line number;
 * Return: no return
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
