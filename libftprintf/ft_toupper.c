/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:09:18 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 16:09:23 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char s = 'H';
	printf("%c", ft_toupper(s));
	printf("%c", toupper(s));
	return(0);
}*/
