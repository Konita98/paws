/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_n_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:29:46 by nerica            #+#    #+#             */
/*   Updated: 2024/04/06 10:42:35 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_printnbr(int nbr)
{
	char	ch;
	int		count;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * (-1);
		count += 1;
	}
	if (nbr > 9)
	{
		count += ft_printnbr(nbr / 10);
		count += ft_printnbr(nbr % 10);
	}
	else
	{
		ch = nbr + '0';
		write(1, &ch, 1);
		count += 1;
	}
	return (count);
}

int	ft_printnbr_u(long int nbr)
{
	char	ch;
	int		count;

	count = 0;
	if (nbr < 0)
		nbr = 4294967296 + nbr;
	if (nbr > 9)
	{
		count += ft_printnbr_u(nbr / 10);
		count += ft_printnbr_u(nbr % 10);
	}
	else
	{
		ch = nbr + '0';
		count += write(1, &ch, 1);
	}
	return (count);
}

int	ft_printptr(void *ptr)
{
	int	count;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_printnbrhexa_long((unsigned long int)ptr);
	return (count);
}
