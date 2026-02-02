/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:27:51 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 18:44:44 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	if (str[0] == '+' || str[0] == '-')
	{
		if (size == 1)
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_convertible(char **entry, int args)
{
	int	i;

	i = 0;
	while (i < args)
	{
		if (!is_num(entry[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**prepare_to_convert(char **entry, int args)
{
	int		i;
	char	*str;
	char	**unified_entry;

	i = 1;
	str = ft_strdup(entry[i]);
	if (args > 1)
	{
		while (i < args)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, entry[i + 1]);
			i++;
		}
	}
	unified_entry = ft_split(str, ' ');
	return (unified_entry);
}

int	*parse_to_int(char **str_arr, int size)
{
	int		i;
	int		*numbers;
	long	long_number;

	numbers = (int *)malloc(size * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		long_number = ft_atol(str_arr[i]);
		if (!(long_number >= INT_MIN && long_number <= INT_MAX))
		{
			free(numbers);
			return (NULL);
		}
		numbers[i] = (int)long_number;
		i++;
	}
	free_array(str_arr);
	return (numbers);
}

int	is_duplicate(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (nums[i] == nums[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
