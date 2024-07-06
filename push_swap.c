
#include "push_swap.h"

void	printlist(t_list	*stack)
{
	t_item *p_temp = stack->first;
        while (p_temp != NULL)
        {
            ft_printf("%d\n", p_temp->value);
            p_temp = p_temp->next;
        }
}

int main(int argc, char *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	char	**formatted;        

	a_stack = initialize();
	b_stack = initialize();
	formatted = formatargv(argc, argv);
	if (!formatted || check_not_numerical(formatted) || check_double(formatted))
	{
		ft_printf("Error\n");
		return (0);
	}
	while(*formatted)
		Stacking_end(a_stack, ft_atoi(*formatted++));
	return 0;
}
