/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:44:59 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 12:45:24 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l;

	l = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while ((*s1 != '\0'))
	{
		*str = (char const)*s1;
		str++;
		s1++;
	}
	while ((*s2 != '\0'))
	{
		*str = (char const)*s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (str - l);
}

/*#include <stdio.h>
int main(void)
{
	printf("ft existant %s\n",ft_strjoin("coucou", "tout le monde"));
	//printf("ft cree %s\n",substr("coucouc tout le monde", 5, 5));
	return (0);
}*/
