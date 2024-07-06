/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:53:31 by nerica-k          #+#    #+#             */
/*   Updated: 2024/02/24 11:53:37 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_bzero(void *s, int n)
{
	char	*str;

	str = (char *)s;
	while (n != 0)
	{
		*str = 0;
		n--;
		str++;
	}
	return (s);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "hello eeryoihlwre";

	ft_bzero(str, 5);
	printf("%s", str);
	return(0);
}*/
