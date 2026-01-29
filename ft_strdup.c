/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:04:24 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/29 20:47:47 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*read;
	int		i;

	cpy = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	read = (char *)s;
	while (read[i])
	{
		cpy[i] = read[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
