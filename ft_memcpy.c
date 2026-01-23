/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:26:31 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/14 19:17:36 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp1;
	const unsigned char	*temp2;

	i = 0;
	temp1 = dest;
	temp2 = src;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	string1[] = "Legal";
	char	string2[] = "Coooooooool";
	char	string3[] = "Coooooooool";
	printf("%s\n", (char *) ft_memcpy(string2, string1, 200));
	printf("%s", (char *) memcpy(string3, string1, 200));
	return(0);
}
*/
