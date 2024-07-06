/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:02:31 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/17 15:22:49 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static long	len_malloc(int n)
{
	int		i;
	int		nb;

	i = 1;
	nb = absolute (n);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		while (nb >= 10)
		{
			i++;
			nb /= 10;
		}
		return (i + 1);
	}
	else
	{
		while (nb >= 10)
		{
			i++;
			nb /= 10;
		}
		return (i);
	}
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;

	len = len_malloc(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n < 0)
		result[0] = 45;
	if (n == 0)
		result[0] = '0';
	while (n != 0 && len > 0)
	{
		result[len - 1] = absolute(n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}
