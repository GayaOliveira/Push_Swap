/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/29 20:47:47 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(int *numbers, int numbers_size, t_stack **a, t_stack **b)
{
	int	*indexes;

	if (numbers_size == 2)
		sort_2(numbers);
	indexes = get_index(numbers, numbers_size);
	create_stack_a(a, numbers, indexes, numbers_size);
	free(numbers);
	free(indexes);
	if (numbers_size == 3)
	{
		sort_3(a, b);
		exit(0);
	}
	position_sort(a, b);
}
