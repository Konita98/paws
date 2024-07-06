/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:17:28 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 09:04:36 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	char			*str1;
	char			*str2;
	int				val;
	unsigned int	i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	val = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			val = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
			return (val);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char src[] = "hello eeryoihlwre";
	char dst[] = "hella can be very useful......";
	printf("ft cree %d \n",ft_memcmp(dst, src, 0));
	printf("ft cree %d",memcmp(dst, src, 0));

	return(0);
}*/
