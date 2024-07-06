/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:13:53 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 09:27:28 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char str)
{
	int	result;

	result = 0;
	if (str == ' ' || str == '\n' || str == '\t'
		|| str == '\v' || str == '\f' || str == '\r')
		result = 1;
	return (result);
}

int	ft_atoi(const char *s)
{
	int		i;
	int		minus;
	int		result;
	char	*str;

	str = (char *)s;
	i = 0;
	minus = 1;
	result = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= (-1);
		i++;
	}
	while (ft_isdigit(str[i]) == 1 && i < ft_strlen(str))
	{
		result = result * 10 + (str[i++] - 48);
	}
	result = result * minus;
	return (result);
	return (0);
}
/*#include <stdio.h>
int main(void)
{
	printf("%d", ft_atoi("6416"));
	return 0;
}*/
