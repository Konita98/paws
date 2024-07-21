/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:23:50 by nerica            #+#    #+#             */
/*   Updated: 2024/07/14 11:23:54 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_rotate_rev(t_list *a, t_list *b, char *command)
{
	if (ft_strncmp(command, "ra", ft_strlen(command)) == 0)
		rotate(a);
	if (ft_strncmp(command, "rb", ft_strlen(command)) == 0)
		rotate(b);
	if (ft_strncmp(command, "rr", ft_strlen(command)) == 0)
	{
		rotate(a);
		rotate(b);
	}
	if (ft_strncmp(command, "rra", ft_strlen(command)) == 0)
		rev_rotate(a);
	if (ft_strncmp(command, "rrb", ft_strlen(command)) == 0)
		rev_rotate(b);
	if (ft_strncmp(command, "rrr", ft_strlen(command)) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	ft_printf("%s\n", command);
	return (1);
}

int	move_swap_push(t_list *a, t_list *b, char *command)
{
	if (ft_strncmp(command, "sa", ft_strlen(command)) == 0)
		swap(a);
	if (ft_strncmp(command, "sb", ft_strlen(command)) == 0)
		swap(b);
	if (ft_strncmp(command, "ss", ft_strlen(command)) == 0)
	{
		swap(a);
		swap(b);
	}
	if (ft_strncmp(command, "pa", ft_strlen(command)) == 0)
		push(a, b);
	if (ft_strncmp(command, "pb", ft_strlen(command)) == 0)
		push(b, a);
	ft_printf("%s\n", command);
	return (1);
}
int	*formatted_int(t_list	*stack)
{
	int	*formatted_tab;
	t_item	*p_temp;
	int	i;

	formatted_tab = (int*) malloc(stack->len * sizeof(int));
	p_temp = stack->first;
	i = 0;
        while (p_temp != NULL)
        {
            formatted_tab[i] = p_temp->value;
            p_temp = p_temp->next;
            i++;
        }
        return(formatted_tab);
}
int	*sort_formatted(t_list	*stack)
{
	int	*formatted_tab;
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = i + 1;
	formatted_tab = formatted_int(stack);
	while(i <= stack->len - 2)
	{
		while(j <= stack->len - 1)
		{
			if (formatted_tab[i] > formatted_tab[j])
			{
				temp = formatted_tab[j];
				formatted_tab[j] = formatted_tab[i];
				formatted_tab[i] =  temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (formatted_tab);	
}

void	get_pos(t_list *stack)
{
	t_item	*p_temp;
	int	*forma;
	int i;

	forma = sort_formatted(stack);
	p_temp = stack->first;
	i = 0;
	while(p_temp != NULL)
	{
		i = 0;
		while ( i < stack->len)
		{
			if(p_temp->value == forma[i])
				p_temp->pos = i;
			i++;
		}
		p_temp = p_temp->next;
	}
}
