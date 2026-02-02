/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:06:44 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		dest[i] = (char)s1[i];
	i = 0;
	while (i < len_s2)
	{
		dest[len_s1 + i] = (char)s2[i];
		i++;
	}
	dest[len_s1 + i] = '\0';
	free(s1);
	return (dest);
}
