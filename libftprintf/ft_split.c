/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:16:29 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/03 14:17:05 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countword(char const *s, char c)
{
	int	count;
	int	i;
	int	bl;

	bl = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && bl == 1)
		{
			count++;
			bl = 0;
		}
		else if (s[i] == c)
			bl = 1;
		i++;
	}
	return (count);
}

static	void	*free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		j;

	j = 0;
	count = countword(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (j < count)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[j++] = ft_substr(s, 0, i);
		if (!tab[j - 1])
			return (free_tab(tab, j - 1));
		s += i;
	}
	tab[count] = NULL;
	return (tab);
}
