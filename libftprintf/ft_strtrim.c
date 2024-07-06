/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:38:34 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/13 17:02:30 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurence(char const	*set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = ft_strlen(s1) - 1;
	while ((occurence (set, s1[i]) == 1) && s1[i] != '\0')
		i++;
	while ((occurence (set, s1[j]) == 1) && j > 0)
		j--;
	if (j == 0 || (i == ft_strlen(s1) - 1))
		trimmed = ft_substr(s1, 0, 0);
	else
		trimmed = ft_substr(s1, i, j - i + 1);
	return (trimmed);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%s\n",ft_strtrim("   xxx   xxx", " x"));
	printf("%d\n",ft_strlen(ft_strtrim("   xxx   xxx", " x")));
	//printf("ft cree %s\n",substr("coucouc tout le monde", 5, 5));
	return (0);
}*/
