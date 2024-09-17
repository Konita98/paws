#include "push_swap.h"

void	top_more_a(t_item *item, t_list *a, t_list *b)
{
	int	mult;

	mult = item->idx;
	if(item->idx >= 0 && item->idx <= a->len / 2)
	{
		while(mult-- > 0)
			move_rotate_rev(a, b, "ra");	
	}
	else if (item->idx <= a->len - 1 && item->idx > a->len / 2)
	{
		while(mult++ < a->len)
			move_rotate_rev(a, b, "rra");	
	}
}

void	top_more_b(t_item *item, t_list *a, t_list *b)
{
	int	mult;

	mult = item->idx;
	if(item->idx > 0 && item->idx <= b->len / 2)
	{
		while(mult-- > 0)
			move_rotate_rev(a, b, "rb");	
	}
	else if (item->idx <= b->len - 1 && item->idx > b->len / 2)
	{
		while(mult++ < b->len - 1)
			move_rotate_rev(a, b, "rrb");
	}
}

t_item	*min(t_list *ab)
{
	t_item	*ptemp;

	ptemp = ab->first;
	get_pos(ab);
	//printlistposition(ab);
	while (ptemp != NULL)
	{
		if (ptemp->pos == 0)
			return (ptemp);
		ptemp = ptemp->next;
	}
	return(ab->first);
}

t_item	*max(t_list *ab)
{
	t_item	*ptemp;

	ptemp = ab->first;
	get_pos(ab);
	while (ptemp != NULL)
	{
		if (ptemp->pos == ab->len - 1)
			return (ptemp);
		ptemp = ptemp->next;
	}
	return(NULL);
}

t_item	*nearestmore(int val, t_list	*stack) // qui est le plu inférieur à l'élément a dans b
{
	t_item	*item;
	int	gap;

	item = stack->first;
	gap = 1;
	while(gap + val <= max(stack)->value)
	{
		item = stack->first;
		while(item != NULL)
		{
			if (item->value == val + gap)
			{
				return (item);
			}
			item = item->next;
		}
		gap++;
	}
	get_pos(stack);
	item = stack->first;
	while(item->pos != 0)
		item = item->next;
	return(item);
}

t_item	*nearestless(int val, t_list	*stack) // qui est le plu inférieur à l'élément a dans b, all that shit
{
	t_item	*item;
	int	gap;

	item = stack->first;
	gap = 1;
	while(val - gap <= min(stack)->value)
	{
		item = stack->first;
		while(item != NULL)
		{
			if (item->value == val - gap)
				return (item);
			item = item->next;
		}
		gap++;
	}
	get_pos(stack);
	item = stack->first;
	while(item->pos != stack->len - 1)
		item = item->next;
	return(item);
}

void	sort_three_items(t_list *a_stack, t_list *b_stack)
{
	while(check_sorted(a_stack) == 0)
	{
		if ((a_stack->first->pos == 0 && a_stack->first->next->pos == 2) 
		|| (a_stack->first->pos == 1 && a_stack->first->next->pos == 0) 
		|| (a_stack->first->pos == 2 && a_stack->first->next->pos == 1))
			move_swap_push(a_stack, b_stack, "sa");
		else if (a_stack->first->pos == 2 && a_stack->first->next->pos == 0)
			move_rotate_rev(a_stack, b_stack, "ra");
		else if (a_stack->first->pos == 1 && a_stack->first->next->pos == 2)
			move_rotate_rev(a_stack, b_stack, "rra");
	}		
}

void	sort_rev_three_items(t_list *a_stack, t_list *b_stack)
{
	while(check_sortedinverse(b_stack) == 1)
	{
		if (b_stack->first->pos == 0 && b_stack->first->next->pos == 2)
			move_swap_push(a_stack, b_stack, "rb");
		else if ((b_stack->first->pos == 2 && b_stack->first->next->pos == 0) 
		|| (b_stack->first->pos == 1 && b_stack->first->next->pos == 2) 
		|| (b_stack->first->pos == 0 && b_stack->first->next->pos == 1))
			move_rotate_rev(a_stack, b_stack, "sb");
		else if (b_stack->first->pos == 1 && b_stack->first->next->pos == 0)	
			move_rotate_rev(a_stack, b_stack, "rrb");
	}
}

void	rearrfromnsorta(t_list *a_stack, t_list *b_stack)
{
	t_item	*nmore;

	while(b_stack->len > 0)
	{
		nmore = nearestmore(b_stack->first->value, a_stack);
		top_more_a(nmore, a_stack, b_stack);
		move_swap_push(a_stack, b_stack, "pb");
	}
	top_more_a(min(a_stack), a_stack, b_stack);
}
void	sort_four_to_six_items(t_list *a_stack, t_list *b_stack)
{
	t_item	*nmore;

	while(a_stack->len > 3)
		move_swap_push(a_stack, b_stack, "pa");
	sort_three_items(a_stack, b_stack);
	ft_printf("\nb_stack\n");
	printlistposition(b_stack);
	ft_printf("\nb_stacklength = %d\n", b_stack->len);
	if(b_stack->len == 2 && check_sortedinverse(b_stack) == 0)
	{	
		move_rotate_rev(a_stack, b_stack, "rb");
		ft_printf("\nb_stack\n");
		printlistposition(b_stack);
	}
	else if(b_stack->len == 3)
		sort_rev_three_items(a_stack, b_stack);
	while(b_stack->len > 0)
	{
		nmore = nearestmore(b_stack->first->value, a_stack);
		ft_printf("nmore = %d index = %d\n", nmore->value, nmore->idx);
		top_more_a(nmore, a_stack, b_stack);
		ft_printf("a \n");
		printlistposition(a_stack);
		ft_printf("\n");
		printlistposition(a_stack);
		move_swap_push(a_stack, b_stack, "pb");
	}
	top_more_a(min(a_stack), a_stack, b_stack);
	rearrfromnsorta(a_stack, b_stack);
}

int	cost(t_item *a, t_item *b, int lena, int lenb)
{
	int idxa;
	int idxb;
	int cost;

	idxa = a->idx;
	idxb = b->idx;
	cost = 0;
	while((idxa != 0 && idxb != 0) || (idxa != lena && idxb != lenb))
	{
		if ((idxa-- <= lena / 2 && idxb-- <= lenb / 2) 
		|| (idxa++ >= lena / 2 && idxb++ >= lenb / 2)
		|| (idxa-- <= lena / 2) || (idxb-- <= lenb / 2)
		|| (idxa++ >= lena / 2) || (idxb++ >= lenb / 2))
			cost++;
	}
	return (cost);
}
		
t_item	*cheapest(t_list *a, t_list *b)
{
	t_item	*tmp;
	t_item	*itb;
	int	min_tmp;

	tmp = a->first;
	itb = nearestless(tmp->pos, b);
	tmp->cost = cost(tmp, itb, a->len, b->len);
	min_tmp = tmp->cost;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		itb = nearestless(tmp->pos, b);
		tmp->cost = cost(tmp, itb, a->len, b->len);
		if (min_tmp > tmp->cost)
			min_tmp = tmp->cost;
		tmp = tmp->next;
	}
	tmp = a->first;
	while (tmp != NULL)
	{
		if (tmp->cost == min_tmp)
			return (tmp);
	}
	return (NULL);
}
	
void sortmore(t_list *a, t_list *b)
{
	move_swap_push(a, b, "pa");
	move_swap_push(a, b, "pa");
	while(a->len > 3)
	{
		top_more_a(cheapest(a,b), a, b);
		top_more_b((nearestless(cheapest(a,b)->pos,b)), a, b);
		move_swap_push(a, b, "pa");
	}
	rearrfromnsorta(a, b);
}
