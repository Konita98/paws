/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:26:25 by nerica            #+#    #+#             */
/*   Updated: 2024/07/06 13:26:30 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *stack)
{
	t_item	*tmp;
	int	i;

	i = 0;
	tmp = stack->first;
	while(tmp)
	{
		tmp->index = i;
		i++;
		tmp= tmp->next;
	}
}
void	swap(t_list *stack)
{
	t_item	*temp;
	t_item	*temp1;

	temp = malloc(sizeof(*temp));
	temp1 = malloc(sizeof(*temp1));
	if (temp == NULL || temp1 == NULL)
		exit(0);
	temp->value = stack->first->value;
	free(stack->first);
	temp1->value = stack->first->next->value;
	free(stack->first->next);
	stack->first = stack->first->next->next;
	stack->first->previous = temp;
	temp->next = stack->first;
	temp->previous = temp1;
	temp1->next = temp;
	stack->first = temp1;
	temp1->previous = NULL;
	indexing(stack);
}

void	rotate(t_list *stack)
{
	t_item	*temp;

	temp = malloc(sizeof(*temp));
	if (temp == NULL)
		exit(0);
	temp->value = stack->first->value;
	free(stack->first);
	stack->first = stack->first->next;
	stack->last->next = temp;
	temp->previous = stack->last;
	stack->last = temp;
	stack->last->next = NULL;
	indexing(stack);
}

void	rev_rotate(t_list *stack)
{
	t_item	*temp;

	temp = malloc(sizeof(*temp));
	if (temp == NULL)
		exit(0);
	temp->value = stack->last->value;
	free(stack->last);
	stack->last = stack->last->previous;
	temp->previous = NULL;
	temp->next = stack->first;
	stack->first = temp;
	stack->last->next = NULL;
	indexing(stack);
}

void	push(t_list *stack1, t_list *stack2)
{
	t_item	*temp;

	temp = malloc(sizeof(*temp));
	if (temp == NULL)
		exit(0);
	temp->value = stack1->first->value;
	temp->next = NULL;
	if (stack2->last == NULL)
	{
		free(stack1->first);
		stack1->first = stack1->first->next;
		temp->previous = NULL;
		stack2->first = temp;
		stack2->last = temp;
	}
	else
	{
		free(stack1->first);
		stack1->first = stack1->first->next;
		stack2->first->previous = temp;
		temp->next = stack2->first;
		stack2->first = temp;
	}
	indexing(stack1);
	indexing(stack2);
}
