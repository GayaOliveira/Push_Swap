/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:18:15 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	bubble_sort(int *numbers, int numbers_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < numbers_size)
	{
		j = i + 1;
		while (j < numbers_size)
		{
			if (numbers[i] > numbers[j])
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*get_index(int *numbers, int numbers_size)
{
	int	*numbers_cpy;
	int	*indexes;
	int	i;
	int	j;

	numbers_cpy = malloc(numbers_size * sizeof(int));
	indexes = malloc(numbers_size * sizeof(int));
	if (!indexes || !numbers_cpy)
		return (NULL);
	ft_memcpy(numbers_cpy, numbers, numbers_size * sizeof(int));
	bubble_sort(numbers_cpy, numbers_size);
	i = 0;
	while (i < numbers_size)
	{
		j = 0;
		while (j < numbers_size)
		{
			if (numbers[i] == numbers_cpy[j])
				indexes[i] = j + 1;
			j++;
		}
		i++;
	}
	free(numbers_cpy);
	return (indexes);
}
