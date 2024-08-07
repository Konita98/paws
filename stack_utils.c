/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:52:48 by nerica            #+#    #+#             */
/*   Updated: 2024/07/06 13:52:54 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**formatargv(int argc, char *argv[])
{
	char	*args;
	int	i;
	char	**tab;

	i = 1;
	args = argv[i];
	if (argc <= 2)
		return (NULL);
	while(++i < argc)
	{
		args = ft_strjoin(args, " ");
		args = ft_strjoin(args, argv[i]);
	}
	tab = ft_split(args, ' ');
	free(args);
	return (tab);	
}

t_list	*initialize(void)
{
	t_item	*piece;
	t_list	*stack;

	piece = malloc (sizeof(*piece));
	stack = malloc (sizeof(*stack));
	if (!stack || !piece)
		exit(EXIT_FAILURE);
	piece->value = 0;
	piece->pos = 0;
	piece->cost = 0;
	piece->next = NULL;
	piece->previous = NULL;
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

t_list	*stacking_end(t_list *stack, int data)
{
	t_item	*piece;

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
		piece->previous = stack->last;
		stack->last = piece;
	}
	stack->len++;
	return (stack);
}

t_list	*stacking_front(t_list *stack, int data)
{
	t_item	*piece;

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
		stack->first->previous = piece;
		piece->next = stack->first;
		stack->first = piece;
	}
	stack->len++;
	return (stack);
}

t_list	*stacking_end_for_move(t_list *stack, int data)
{
	t_item	*piece;

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
		piece->previous = stack->last;
		stack->last = piece;
	}
	stack->len++;
	return (stack);
}
