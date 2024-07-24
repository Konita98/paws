#include "push_swap.h"

void	printlist(t_list *stack)
{
	t_item *p_temp;

	p_temp = stack->first;
        while (p_temp != NULL)
        {
            ft_printf("%d\n", p_temp->value);
            p_temp = p_temp->next;
        }
}
void	printlistposition(t_list	*stack)
{
	t_item *p_temp;

	p_temp = stack->first;
        while (p_temp != NULL)
        {
            ft_printf("%d   %d\n", p_temp->value, p_temp->pos);
            p_temp = p_temp->next;
        }
}

void	printindex(t_list	*stack)
{
	t_item *p_temp;

	p_temp = stack->first;
        while (p_temp != NULL)
        {
            ft_printf("%d   %d\n", p_temp->value, p_temp->idx);
            p_temp = p_temp->next;
        }
}
