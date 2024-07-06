/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerica-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 08:43:39 by nerica-k          #+#    #+#             */
/*   Updated: 2024/03/02 09:33:04 by nerica-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	if (size < 0 && nmemb < 0)
		return (NULL);
	if (size * nmemb < 0)
		return (NULL);
	if (size >= 2147483647 || nmemb >= 2147483647)
		return (NULL);
	ptr = malloc((nmemb * size) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int	main(void)
{
	char* ptr = (char*) calloc(25, sizeof(float));
	if(ptr == NULL) {
    		printf("Error! memory not allocated.");
   		 exit(0);
	}
	else
	{
		printf("ft cree: %s hey", ptr);
	}
	char* ptr1 = (char*) ft_calloc(25, sizeof(float));
	if(ptr1 == NULL) {
    		printf("Error! memory not allocated.");
   		 exit(0);
	}
	else
	{
		printf("ft cree: %s hey", ptr1);
	}
	free(ptr);
	free(ptr1);
	return(0);
}*/
