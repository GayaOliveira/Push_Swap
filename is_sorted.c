/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:59:04 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:07:20 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *numbers, int numbers_size)
{
	int	i;

	i = 0;
	while (i < numbers_size - 1)
	{
		if (numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	free(numbers);
	return (1);
}
