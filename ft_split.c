/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:13:00 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/29 20:47:47 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	is_allocated(char **arr, int j)
{
	if (arr[j] == NULL)
	{
		while (j >= 0)
		{
			free(arr[j]);
			j--;
		}
		free(arr);
		return (0);
	}
	return (1);
}

static char	**populate_array(char const *s, char c, char **arr)
{
	size_t	start;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[j] = (char *)malloc((i - start + 1) * sizeof(char));
			if (!is_allocated(arr, j))
				return (NULL);
			ft_memcpy(arr[j], s + start, i - start);
			*(arr[j++] + i - start) = '\0';
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		n_words;

	if (s == NULL)
		return (NULL);
	n_words = count_words(s, c);
	array = (char **)malloc((n_words + 1) * sizeof(char *));
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}
	populate_array(s, c, array);
	free(s);
	return (array);
}
