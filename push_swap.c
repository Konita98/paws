
#include "push_swap.h"

void	push_swap(int argc,char *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	char **pile_tab;

	a_stack = initialize();
	b_stack = initialize();
	pile_tab = formatargv(argc, argv);
	if (!pile_tab || check_not_numerical(pile_tab) || check_double(pile_tab))
	{
		ft_printf("Error\n");
		exit(0);
	}
	while(*pile_tab)
		stacking_end(a_stack, ft_atoi(*pile_tab++));
		
	
	//ft_printf("stack\n");
	indexing(a_stack);
	
	ft_printf("\nstack before\n");
	printlistposition(a_stack);
	//printindex(a_stack);
	//ft_printf("stack sorted\n");
	if (a_stack->len == 3)
		sort_three_items(a_stack, b_stack);
	else if (a_stack->len > 3 || a_stack->len <= 6 )
	{
		sort_four_to_six_items(a_stack, b_stack);
		//ft_printf("b1\n");
		//printlistposition(b_stack);
	}
	indexing(a_stack);
	get_pos(a_stack);
	
	ft_printf("\nstack after\n");
	printlistposition(a_stack);
}

int main(int argc, char *argv[])
{
	char	**formatted;

	formatted = formatargv(argc, argv);
	if (!formatted || check_not_numerical(formatted) || check_double(formatted))
	{
		ft_printf("Error\n");
		return (0);
	}
	push_swap(argc, argv);
	
	return 0;
}
