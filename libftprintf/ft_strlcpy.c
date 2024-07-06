/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:45:58 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 15:46:02 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	if (!size)
		return (ft_strlen(s));
	else
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen(s));
}

/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char src[] = "hello eeryoihlwre";
	char dst[] = "my name is erica kone";
	printf("ft cree: %d \n", ft_strlcpy(dst, src, strlen(src)));
	return(0);
}*/
