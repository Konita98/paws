#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/libft.h"
# include <stdlib.h>
# include <limits.h>
# define EXIT_SUCCESS 1
# define EXIT_FAILURE 0

typedef struct Item Item;
struct Item	
{
	int	value;
	int	position;
	int	cost;
	Item	*next;
	Item	*previous;
};
typedef struct List List;
struct List
{
	int	len;
	Item	*first; 
	Item	*last;
};


char	**formatargv(int argc, char *argv[]);
int	 len(char **tab);
int	check_double(char **tab);
int	ft_isspace(char str);
int	check_not_numerical(char **tab);

List	*initialize();
List	*Stacking_end(List *stack, int data);
List	*Stacking_front(List *stack, int data);
void	swap(List *stack);
void reverse (List *stack);
#endif /*__PUSH_SWAP_H__*/
