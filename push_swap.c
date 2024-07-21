
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


t_list	*push_swap(char **pile_tab)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = initialize();
	b_stack = initialize();
	while(*pile_tab)
		Stacking_end(a_stack, ft_atoi(*pile_tab++));
	ft_printf("stack\n");
	printlist(a_stack);
	ft_printf("stack sorted\n");
	if (a_stack->len == 3)
		sort_three_items(a_stack, b_stack);
	printlist(a_stack);
	return(a_stack);
}

int main(int argc, char *argv[])
{
	t_list	*a_stack;
	char	**formatted;

	formatted = formatargv(argc, argv);
	if (!formatted || check_not_numerical(formatted) || check_double(formatted))
	{
		ft_printf("Error\n");
		return (0);
	}
	a_stack = push_swap(formatted);
	ft_printf("stack\n");
	printlist(a_stack);
	
	return 0;
}
