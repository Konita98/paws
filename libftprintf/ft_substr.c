/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:56 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 11:57:39 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	void	*str_malloc(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_malloc;

	if (start > (unsigned int)ft_strlen((char *)s))
		len_malloc = 0;
	else if (start + (unsigned int)len < (unsigned int)ft_strlen((char *)s))
		len_malloc = len;
	else if (start + (unsigned int)len >= (unsigned int)ft_strlen((char *)s))
		len_malloc = (unsigned int)ft_strlen((char *)s) - start;
	else if (start > (unsigned int)ft_strlen((char *)s))
		len_malloc = 0;
	else
		len_malloc = 0;
	return ((char *)malloc((len_malloc + 1) * sizeof(char)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char			*str;
	unsigned int	i;
	unsigned int	j;

	str = (char *) s;
	if (!s)
		return (NULL);
	substr = (char *)str_malloc(s, start, len);
	i = start;
	j = 0;
	if (!substr)
		return (NULL);
	while (i < ((unsigned int)ft_strlen(str) + 1) && j < len)
	{
		substr[j] = str[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

/*int main(void)
{
	char *res = ft_substr("1", 42, 42000000);
	printf("malloc1 %s\n", res);
	free(res);
	//printf("malloc1 %s\n",ft_substr("0123456789", 9, 10));
	//printf("malloc1 %s\n",ft_substr("BONJOUR LES HARICOTS !", 8, 14));
	//printf("ft cree %s\n",substr("coucouc tout le monde", 5, 5));
	return (0);
}*/
