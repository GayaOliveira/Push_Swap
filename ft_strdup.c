/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:04:24 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/09 20:53:36 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*read;
	int		i;

	cpy = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	read = (char *) s;
	while (read[i])
	{
		cpy[i] = read[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Testando";
	
	printf("%s\n", ft_strdup(str));
	printf("%s\n", strdup(str));

}
*/
