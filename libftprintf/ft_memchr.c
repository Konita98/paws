/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:53:27 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 09:13:37 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void	*s, int c, int n)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (char) c)
		{
			return (str);
		}
		i++;
		str++;
	}
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
int	main(void)
{
	char* str = "Hellor bicth of everyone";
	printf("extract %s\n", (char*)ft_memchr(str, 'r',10));
	printf("extract %s\n", (char*)memchr(str, 'r',10));
	return(0);
}*/
