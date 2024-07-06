/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:57:16 by nerica            #+#    #+#             */
/*   Updated: 2024/03/31 11:00:45 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbrhex_upper(unsigned int n)
{
	int		count;
	char	ch;

	count = 0;
	if (n >= 16)
	{
		count += ft_printnbrhex_upper(n / 16);
		count += ft_printnbrhex_upper(n % 16);
	}
	else if (n >= 10)
	{
		ch = n - 10 + 'A';
		count += write(1, &ch, 1);
	}
	else if (n <= 9)
	{
		ch = n + '0';
		count += write(1, &ch, 1);
	}
	return (count);
}

int	ft_printnbrhex(unsigned int n)
{
	int		count;
	char	ch;

	count = 0;
	if (n >= 16)
	{
		count += ft_printnbrhex(n / 16);
		count += ft_printnbrhex(n % 16);
	}
	else if (n >= 10)
	{
		ch = n - 10 + 'a';
		count += write(1, &ch, 1);
	}
	else if (n < 10)
	{
		ch = n + '0';
		count += write(1, &ch, 1);
	}
	return (count);
}

int	ft_printnbrhexa_long(unsigned long int n)
{
	int		count;
	char	ch;

	count = 0;
	if (n >= 16)
	{
		count += ft_printnbrhexa_long(n / 16);
		count += ft_printnbrhexa_long(n % 16);
	}
	else if (n >= 10)
	{
		ch = n - 10 + 'a';
		count += write(1, &ch, 1);
	}
	else if (n < 10)
	{
		ch = n + '0';
		count += write(1, &ch, 1);
	}
	return (count);
}
