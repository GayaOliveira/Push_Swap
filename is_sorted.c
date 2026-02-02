/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:59:04 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
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
