#include "push_swap.h"

void	sort_three_items(t_list *stack1, t_list *stack2)
{
	while(check_sorted(stack1) == 0)
	{
		if ((stack1->first->pos == 0 && stack1->first->next->pos == 2) 
		|| (stack1->first->pos == 1 && stack1->first->next->pos == 0) 
		|| (stack1->first->pos == 2 && stack1->first->next->pos == 1))
			move_swap_push(stack1, stack2, "sa");
		if (stack1->first->pos == 2 && stack1->first->next->pos == 0)
			move_rotate_rev(stack1, stack2, "ra");
		if (stack1->first->pos == 1 && stack1->first->next->pos == 2)
			move_rotate_rev(stack1, stack2, "rra");
	}	
}

int	nearest_less(int pos, t_list	*stack)
{
	t_item	*item;
	int	gap;
	int	tmp;

	item = stack->first;
	gap = stack->first->pos - pos;
	while(item != NULL)
	{
		tmp = item->pos - pos;
		if(tmp < gap)
			gap = tmp;
		item = item->next;
	}
	return (gap + pos);
}

int	nearest_more(int pos, t_list	*stack)
{
	t_item	*item;
	int	gap;
	int	tmp;

	item = stack->first;
	gap = stack->first->pos - pos;
	while(item != NULL)
	{
		tmp = item->pos - pos;
		if(tmp > gap)
			gap = tmp;
		item = item->next;
	}
	return (pos + gap);
}

void	cheapest_move(t_list *a_stack, t_list *b_stack)
{
	t_item	*a;
	t_item	*b;
	int	i;
	int	pos;

	a = a_stack->first;
	b = b_stack->first;
	i = 0;
	while(a_item != NULL)
	{
		pos = nearest_less(a_item->pos, a_stack);
		while(b != NULL)
		{
			if(b->pos == pos)
				break;
			b = b->next;
		}
		if (a->idx == 0)
			
		if (a->idx == 1)
		{
			if(b->idx == 1)
				i++;
			else
				i++;
		}
		else if(a->idx > 1 && a->idx < idx / 2)
		{
			if(b->idx >= 1 && b->idx < idx / 2)
				i++;
		}
		else
		
	}
	
