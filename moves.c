#include "push_swap.h"

void	swap(List *stack)
{	
	struct Item *temp;
	struct Item *temp1;

	temp = malloc(sizeof(*temp));
	temp1 = malloc(sizeof(*temp1));
	if(temp == NULL || temp1 == NULL)
		exit(0);
	temp->value = stack->first->value;
	ft_printf("temp = %d\n", temp->value);
	temp1->value = stack->first->next->value;
	ft_printf("temp1 = %d\n", temp1->value);
	stack->first = stack->first->next->next;
	stack->first->previous = temp;
	temp->next = stack->first;
	temp->previous = temp1;
	temp1->next = temp;
	stack->first = temp1;
	temp1->previous = NULL;
	ft_printf("valeur first in function swap = %d\n", stack->first->value);
	printlist(stack);
	free(temp);
	free(temp1);	
}

void	reverse (List *stack)
{
	struct Item *temp;

	temp = malloc(sizeof(*temp));
	if(temp == NULL)	
		exit(0);
	temp->value = stack->first->value;
	temp->next=NULL;
	stack->first = stack->first->next;
	stack->last->next = temp;
	temp->previous = stack->last;
	stack->last = temp;
	free(temp);
}

void	push(List *stack1, List *stack2)
{
	struct Item *temp;

	temp = malloc(sizeof(*temp));
	if(temp == NULL)
		exit(0);
	temp = stack1->first;
	if(stack2->last == NULL)
	{
		stack2->first = temp;
		stack2->last = temp;
		stack1->first = stack1->first->next;
	}
	else
	{
		stack1->first = stack1->first->next;
		stack2->first->previous = temp;
		stack2->first = temp;
	}
	free(temp);
}
