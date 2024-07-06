/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:52:00 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 15:52:03 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	result;
	char	*s;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	i = len;
	s = (char *)src;
	if (size > len)
		result = len + (size_t)ft_strlen(s);
	else
		result = size + (size_t)ft_strlen(s);
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (result);
}
