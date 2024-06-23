#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/libft.h"
# include <stdlib.h>
typedef struct Item Item;
struct Item
{
	int	value;
	Item	*next;
	Item	*previous;
};
typedef struct List List;
struct List
{
	Item	*first;	
};
#endif /*__PUSH_SWAP_H__*/
