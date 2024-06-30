
#include "push_swap.h"

List	*initialize()
{
	struct Item	*piece;
	struct List	*stack;

	piece = malloc (sizeof(*piece));
	stack = malloc (sizeof(*stack));
	if (!stack || !piece)
		exit(EXIT_FAILURE);
	piece->value = 0;
	piece->position = 0;
	piece->cost = 0;
	piece->next = NULL;
	piece->previous = NULL;
	stack->len = 0;
	stack->first = NULL;	
	stack->last = NULL;
	return (stack);
}

List	*Stacking_end(List *stack, int data)
{
	struct Item	*piece;

	piece = malloc (sizeof(*piece));
	if (!piece)
		exit(EXIT_FAILURE);
	piece->value = data;
	piece->next = NULL;
	if (stack->last == NULL)
	{
		piece->previous = NULL;
		stack->first = piece;
		stack->last = piece;
	}
	else
	{
		stack->last->next = piece;
		piece->previous=stack->last;
		stack->last=piece;
	}
	stack->len++;
	return(stack);	
}

List	*Stacking_front(List *stack, int data)
{
	struct Item	*piece;

	piece = malloc (sizeof(*piece));
	if (!piece)
		exit(EXIT_FAILURE);
	piece->value = data;
	piece->next = NULL;
	if (stack->last == NULL)
	{
		piece->previous = NULL;
		stack->first = piece;
		stack->last = piece;
	}
	else
	{
		stack->first->previous=piece;
		piece->next = stack->first;
		stack->first = piece;
	}
	stack->len++;
	return(stack);
}
