/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: nerica <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:42:32 by nerica            #+#    #+#             */
/*   Updated: 2024/03/29 08:45:54 by nerica           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_print_acc_format(char format, va_list pt)
{
	if (format == 'c')
		return (ft_printchar(va_arg(pt, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(pt, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(pt, int)));
	else if (format == 'u')
		return (ft_printnbr_u(va_arg(pt, unsigned int)));
	else if (format == '%')
		return (ft_printchar('%'));
	else if (format == 'x')
		return (ft_printnbrhex(va_arg(pt, unsigned int)));
	else if (format == 'X')
		return (ft_printnbrhex_upper(va_arg(pt, unsigned int)));
	else if (format == 'p')
		return (ft_printptr(va_arg(pt, void *)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += ft_print_acc_format(str[i + 1], ptr);
			i += 2;
		}
		else
			count += ft_printchar(str[i++]);
	}
	va_end(ptr);
	return (count);
}
