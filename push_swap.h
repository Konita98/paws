/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:42:03 by nerica            #+#    #+#             */
/*   Updated: 2024/07/06 13:42:07 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct Item	Item;
struct Item	
{
	int	value;
	int	position;
	int	cost;
	Item	*next;
	Item	*previous;
};
typedef struct List	List;
struct List
{
	int	len;
	Item	*first;
	Item	*last;
};
char	**formatargv(int argc, char *argv[]);
int	len(char **tab);
int	check_double(char **tab);
int	ft_isspace(char str);
int	check_not_numerical(char **tab);
void	printlist(List	*stack);
List	*initialize();
List	*Stacking_end(List *stack, int data);
List	*Stacking_front(List *stack, int data);
void	swap(List *stack);
void	rotate(List *stack);
void	rev_rotate(List *stack);
void	push(List *stack1, List *stack2);
#endif /*__PUSH_SWAP_H__*/
