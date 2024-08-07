
#include "push_swap.h"

int	 len(char **tab)
{
	int	i;

	i = 0;
	while(tab[i] != NULL)
		i++;
	return (i);
}

int	check_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < len(tab))
	{
		while (j < len(tab))
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}


int	ft_isspace(char str)
{
	int	result;

	result = 0;
	if (str == ' ' || str == '\n' || str == '\t'
		|| str == '\v' || str == '\f' || str == '\r')
		result = 1;
	return (result);
}


int	check_not_numerical(char **tab)
{
	int	i;

	i = 0;
	while(*tab != NULL)
	{
		if(ft_atoi(*tab) < INT_MIN || ft_atoi(*tab) > INT_MAX)
			return(1);
		if(ft_atoi(*tab) == 0)
		{
			while (ft_isspace(*tab[i]) == 1 || *tab[i] == 45 || *tab[i] == 43)
				i++;
			if (**tab != 48)
				return(1);
		}
		tab++;
	}
	return(0);
}

int	check_sorted(t_list *stack)
{
	t_item	*p_temp;

	indexing(stack);
	get_pos(stack);
	p_temp = stack->first;
	while(p_temp != NULL)
	{
		if (p_temp->pos != p_temp->idx)
			return (0);
		p_temp = p_temp->next;
	}
	return (1);
}

int	check_sortedinverse(t_list *stack)
{
	t_item	*p_temp;

	indexing(stack);
	get_pos(stack);
	p_temp = stack->first;
	while(p_temp != NULL)
	{
		if (p_temp->pos != stack->len - 1 - p_temp->idx)
			return (0);
		p_temp = p_temp->next;
	}
	return (1);
}
