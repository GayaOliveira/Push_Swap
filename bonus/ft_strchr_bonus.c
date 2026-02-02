/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:49:16 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 18:43:25 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			occ = (char *)&s[i];
			return (occ);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
