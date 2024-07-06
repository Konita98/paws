/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:37:48 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/25 09:37:51 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
int	main(void)
{
	char* str = "Hellor bicth of everyone";
	printf("extract %s\n", ft_strrchr(str, 'r'));
	printf("extract %s\n", strchr(str, 'r'));
	return(0);
}*/
