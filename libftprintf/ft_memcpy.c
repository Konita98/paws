/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:21:00 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 12:21:03 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *d, const void *s, int n)
{
	char	*src;
	char	*dest;
	int		i;

	i = 0;
	src = (char *) s;
	dest = (char *) d;
	if (!d && !s)
		return (0);
	while (n != 0)
	{
		dest[i] = src[i];
		n--;
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char src[] = "kjgfjhbntjjjjjjjjjjjjjjjjjjj";
	char dst[] = "zy^@xw^@v";
	ft_memcpy(dst, src, 6);
	//memcpy(dst, src, 5);
	printf("%s", dst );
	return(0);
}*/
