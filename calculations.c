#include "push_swap.h"

void	sort_three_items(t_list *a_stack, t_list *b_stack)
{
	while(check_sorted(a_stack) == 0)
	{
		if ((a_stack->first->pos == 0 && a_stack->first->next->pos == 2) 
		|| (a_stack->first->pos == 1 && a_stack->first->next->pos == 0) 
		|| (a_stack->first->pos == 2 && a_stack->first->next->pos == 1))
			move_swap_push(a_stack, b_stack, "sa");
		if (a_stack->first->pos == 2 && a_stack->first->next->pos == 0)
			move_rotate_rev(a_stack, b_stack, "ra");
		if (a_stack->first->pos == 1 && a_stack->first->next->pos == 2)
			move_rotate_rev(a_stack, b_stack, "rra");
	}		
}

void	sort_reverse_three_items(t_list *a_stack, t_list *b_stack)
{
	
	while(check_sortedinverse(b_stack) == 0)
	{
		if (b_stack->first->pos == 0 && b_stack->first->next->pos == 2)
			move_swap_push(a_stack, b_stack, "rb");
		if ((b_stack->first->pos == 2 && b_stack->first->next->pos == 0) || (b_stack->first->pos == 1 && b_stack->first->next->pos == 2) || (b_stack->first->pos == 0 && b_stack->first->next->pos == 1))
			move_rotate_rev(a_stack, b_stack, "sb");
		if (b_stack->first->pos == 1 && b_stack->first->next->pos == 0)
			move_rotate_rev(a_stack, b_stack, "rrb");
	}
	get_pos(b_stack);
	
}
void	sort_five_items(t_list *a_stack, t_list *b_stack)
{
	while(a_stack->len != 3)
	{
		move_swap_push(a_stack, b_stack, "pa");
		ft_printf("%d", a_stack->len);
	}
	sort_three_items(a_stack, b_stack);
	if(b_stack->len == 2 && check_sortedinverse(b_stack) == 0)
		move_swap_push(a_stack, b_stack, "sb");
	else if(b_stack->len == 3)
		sort_reverse_three_items(a_stack, b_stack);	
	while(b_stack->len != 0)
		move_swap_push(a_stack, b_stack, "pb");	
}
t_item	*nearestless(int posa, t_list	*stackb) // qui est le plu inférieur à l'élément a dans b
{
	t_item	*item;
	int	gap;

	item = stackb->first;
	gap = 1;
	while(gap < posa)
	{
		while(item != NULL)
		{
			if (item->pos == posa - gap)
				return (item);
			item = item->next;
				
		}
		gap++;
	}
	return(NULL);
}

/*t_lsmove	*initializemove(void)
{
	t_lsmove	*movess;
	t_move	*move;

	movess = malloc (sizeof(*movess));
	move = malloc (sizeof(*move));
	if (!moves || !move)
		exit(EXIT_FAILURE);
	move->value = NULL;
	move->next = NULL;
	movess->first = NULL;
	return (moves);
}*/

/*int	*cost_to_top(t_item *a, t_item *b, int len, int idxa, int indb) // has the commands per move as well to be used at each move, len of stacj
{
	int	cost;

	cost = 0;
	if(a->idxa == 1 && b->idxb == 1)
		cost = 1;		//move= "sb";
	else if (a->idxa <= len / 2 && b->idxb <= len / 2)
		cost = 1;
	else if (b->idxa >= len / 2 && b->idxb >= len / 2)
		cost = 1;
	else
	{
		if(a->idxa == 1)
			move = "sa";
		else if(a->idx <= a->len / 2)
			move = "ra";
		else
			move = "rra";
		if(b->idxb == 1)
			move = "sb";
		else if(b->idxb <= b->len / 2)
			move = "rb";
		else
			move = "rrb";
	}
	return (move);
}*/

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

int	min(int	*tab, int len)
{
	int	min;
	int	i;

	min = tab[0];
	i = 0;
	while(i++ < len)
	{
		if (tab[i] < min)
			min = tab[i];
	}
	return (min);
}

int	max(int	*tab, int len)
{
	int	max;
	int	i;

	max = tab[0];
	i = 0;
	while(i++ < len)
	{
		if (tab[i] < max)
			max = tab[i];
	}
	return (max);
}

/*t_list *cheapest_item(t_list *a, t_list *b)
{
	t_item	*tmp;
	t_item	*itb;
	//int	min_cost;
	int	*tab;

	tmp = a->first;
	tab = malloc(sizeof(int) * a->len);
	if (tab == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		itb = nearestless(tmp->pos, b);
		tmp->cost = cost(tmp, itb, a->len, b->len);
		*tab++ = cost(tmp, itb, a->len, b->len);
		tmp = tmp->next;
	}	
}*/
	
