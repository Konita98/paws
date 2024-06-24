

#include "push_swap.h"
#include <stdio.h>

char	**formatargv(int argc, char *argv[])
{
	char	*args;
	int	i;
	char	**tab;

	i = 1;
	args = argv[i];
	while(++i < argc)
	{
		args = ft_strjoin(args, " ");
		args = ft_strjoin(args, argv[i]);
	}
	tab = ft_split(args, ' ');
	free(args);
	return (tab);	
}

int	check_double(int argc, char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}


static int	ft_isspace(char str)
{
	int	result;

	result = 0;
	if (str == ' ' || str == '\n' || str == '\t'
		|| str == '\v' || str == '\f' || str == '\r')
		result = 1;
	return (result);
}


int	check_not_numerical(char **tab)
{
	int	i;

	i = 0;
	while(*tab != NULL)
	{
		if(ft_atoi(*tab) < INT_MIN || ft_atoi(*tab) > INT_MAX)
			return(1);
		if(ft_atoi(*tab) == 0)
		{
			while (ft_isspace(*tab[i]) == 1 || *tab[i] == 45 || *tab[i] == 43)
				i++;
			if (**tab != 48)
				return(1);
		}
		tab++;
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
	/*Item	*a_stack;
	Item	*b_stack;
	

	a_stack = initialize();
	b_stack = initialize();*/
	/*if (argc == 1 || check_double(argc, argv) == 1 || check_numerical(argc, argv) == 1)
	{
		ft_printf("Error");
		return(0);
	}*/
	char	**formatted;
	int	i;

	i= 0;
	formatted = formatargv(argc, argv);
	//ft_printf("%s", *formatted);	
	while (*formatted != NULL)
	{
		ft_printf("%s", *formatted);
		formatted++;
		i++;
	}
	formatted -= i;
	if (check_not_numerical(formatted))
		ft_printf("Error non numerical \n");
	/*if (check_double(argc, formatted))
		ft_printf("Error double");*/
		
	while (*formatted != NULL)
	{
		ft_printf("%s", *formatted);
		formatted++;
	}
	return 0;
}
