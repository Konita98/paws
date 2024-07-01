#include "push_swap.h"

void	swap(List *stack)
{	
	struct Item temp;

	temp = malloc(sizeof(*temp));
	if(temp == NULL)
		exit(EXIT_FAILURE);
	temp = stack->first->next;
	stack->first->next = stack->first->next->next;
	stack->first->previous = temp;
	stack->first = temp;
	free(temp);	
}

void reverse (List *stack)
{
	struct Item temp;

	temp = malloc(sizeof(*temp));
	if(temp == NULL)
		exit(EXIT_FAILURE);
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
	temp->previous = stack->last;
	stack->last = temp;
	free(temp);
}
