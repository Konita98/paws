

#include "push_swap.h"
#include <stdio.h>

int	check_double(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	j = i + 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return(1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return(0);
}

Item	*initialize()
{
	Item	*stack;

	stack = malloc (sizeof(List));
	if (stack == NULL)
		exit(EXIT_FAILURE);
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}

int main(int argc, char *argv[])
{
	Item	a_stack;
	Item	b_stack;

	if (argc == 1 ||check_double(argc, argv) == 1)
	{
		ft_printf("Error");
		return(0);
	}
	a_stack = initialize();
	b_stack = initialize();
	
	return 0;
}
