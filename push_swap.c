
#include "push_swap.h"

List	*initialize();

int main(int argc, char *argv[])
{
	struct List	*a_stack;
	char	**formatted;        

	a_stack = initialize();
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
	struct Item *p_temp = a_stack->first;
        while (p_temp)
        {
            ft_printf("%d\n", p_temp->value);
            p_temp = p_temp->next;
        }
	return 0;
}
