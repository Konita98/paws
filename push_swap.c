

#include "push_swap.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	int i;
	i = 1;
	while (i < argc - 1)
	{
		if(ft_atoi(argv[i]) != 0)
			ft_printf("hello");
		i++;
	}
	return 0;
}
