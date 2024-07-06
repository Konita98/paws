/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:02:42 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 09:30:53 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*sbig;
	char		*sl;
	size_t		len_l;

	i = 0;
	sbig = (char *)big;
	sl = (char *)little;
	len_l = (size_t)ft_strlen(sl);
	if (sbig[i] == '\0')
	{
		if (sl[i] == '\0')
			return (sbig);
		else
			return (NULL);
	}
	while (*sbig)
	{
		if (ft_strncmp(sbig, sl, len_l) == 0 && (i + len_l) <= len)
			return (sbig);
		sbig++;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "aaabc", 5));
	return 0;
}*/
