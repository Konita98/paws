/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:42:03 by nerica            #+#    #+#             */
/*   Updated: 2024/07/06 14:50:01 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_item	t_item;
struct s_item
{
	int		value;
	int		position;
	int		cost;
	t_item	*next;
	t_item	*previous;
};
typedef struct s_list	t_list;
struct s_list
{
	int		len;
	t_item	*first;
	t_item	*last;
};	
char	**formatargv(int argc, char *argv[]);
int		len(char **tab);
int		check_double(char **tab);
int		ft_isspace(char str);
int		check_not_numerical(char **tab);
void	printlist(t_list	*stack);
t_list	*initialize(void);
t_list	*Stacking_end(t_list *stack, int data);
t_list	*Stacking_front(t_list *stack, int data);
void	swap(t_list *stack);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);
void	push(t_list *stack1, t_list *stack2);
#endif /*__PUSH_SWAP_H__*/
