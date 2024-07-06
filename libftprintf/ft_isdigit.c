/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:25:56 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 08:26:00 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	if (!ft_isascii(a))
		return (0);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	//char q='4';
	printf("%d", ft_isdigit(530));
	printf("%d", isdigit(530));
	return 0;
}*/
