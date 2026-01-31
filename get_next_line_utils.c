/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:10:18 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/30 21:33:57 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t		i;
	size_t		i2;
	char		*result;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{	
		result[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		result[i] = s2[i2];
		i2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	// if (s1)
	// 	free(s1);
	return (res);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char		*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
