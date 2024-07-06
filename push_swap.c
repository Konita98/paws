
#include "push_swap.h"

List	*initialize();

void	printlist(List	*stack)
{
	struct Item *p_temp = stack->first;
        while (p_temp != NULL)
        {
            ft_printf("%d\n", p_temp->value);
            p_temp = p_temp->next;
        }
}

int main(int argc, char *argv[])
{
	struct List	*a_stack;
	struct List	*b_stack;
	char	**formatted;        

	a_stack = initialize();
	b_stack = initialize();
	formatted = formatargv(argc, argv);
	if (!formatted || check_not_numerical(formatted) || check_double(formatted))
	{
		ft_printf("Error\n");
		return (0);
	}
	//stacking a
	while(*formatted)
		Stacking_end(a_stack, ft_atoi(*formatted++));
	//sort a
	//afficher a
	ft_printf("valeur first = %d\n", a_stack->first->value);
	ft_printf("valeur last = %d\n", a_stack->last->value);
	printlist(a_stack);
        swap(a_stack);
        ft_printf("after swap\n");
        printlist(a_stack);
	return 0;
}
