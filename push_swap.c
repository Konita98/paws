
#include "push_swap.h"

void	printlist(t_list	*stack)
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
            ft_printf("%d   %d\n", p_temp->value, p_temp->position);
            p_temp = p_temp->next;
        }
}

int	*formatted_int(t_list	*stack)
{
	int	*formatted_tab;
	t_item	*p_temp;
	int	i;

	formatted_tab = (int*) malloc(stack->len * sizeof(int));
	p_temp = stack->first;
	i = 0;
        while (p_temp != NULL)
        {
            formatted_tab[i] = p_temp->value;
            p_temp = p_temp->next;
            i++;
        }
        return(formatted_tab);
}
int	*sort_formatted(t_list	*stack)
{
	int	*formatted_tab;
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = i + 1;
	formatted_tab = formatted_int(stack);
	while(i <= stack->len - 2)
	{
		while(j <= stack->len - 1)
		{
			if (formatted_tab[i] > formatted_tab[j])
			{
				temp = formatted_tab[j];
				formatted_tab[j] = formatted_tab[i];
				formatted_tab[i] =  temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (formatted_tab);	
}



int main(int argc, char *argv[])
{
	t_list	*a_stack;
	//t_list	*b_stack;
	char	**formatted;
	int i;
	t_item	*p_temp;

	a_stack = initialize();
	i = 0;
	//b_stack = initialize();
	formatted = formatargv(argc, argv);
	if (!formatted || check_not_numerical(formatted) || check_double(formatted))
	{
		ft_printf("Error\n");
		return (0);
	}
	while(*formatted)
		Stacking_end(a_stack, ft_atoi(*formatted++));
	ft_printf("stack\n");
	printlist(a_stack);
	ft_printf("\n sorted \n");
	int	*forma;
	forma = sort_formatted(a_stack);
	p_temp = a_stack->first;
	while(p_temp != NULL)
	{
		i = 0;
		while ( i < a_stack->len)
		{
			if(p_temp->value == forma[i])
				p_temp->position = i;
			i++;
		}
		p_temp = p_temp->next;
	}
	printlistposition(a_stack);
	
	return 0;
}
