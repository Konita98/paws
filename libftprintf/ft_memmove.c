/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:38:52 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/17 11:32:06 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, unsigned long n)
{
	char				*src;
	char				*dest;
	unsigned long		i;

	src = (char *) s;
	dest = (char *) d;
	i = 0;
	if (n == 0)
		return (dest);
	if (!d & !s)
		return (0);
	if (s <= d)
	{
		i = n - 1;
		while (i > 0)
		{
			dest[i] = src[i];
			i--;
		}
		dest[i] = src[i];
		return (dest);
	}
	return (ft_memcpy(d, s, n));
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
//your memmove does not segfault when null params is sent
	char *src = "thanks to @apellicc for this test !\r\n";
 	char dst1[0xF0];
 	int size = strlen(src);
 	char *r1 = memmove(dst1, src, size);
 	char *r2 = ft_memmove(dst1, src, size);
 	r1 = memmove("", "" - 1, 0);
 	r2 = ft_memmove("", "" - 1, 0);

	printf("ft 1: %s\n", r1);
	printf("ft 2: %s\n", r2);
	return(0);
}*/
