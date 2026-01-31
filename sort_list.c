/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/30 16:27:29 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(int *numbers, int numbers_size, t_stack **a, t_stack **b)
{
	if (numbers_size == 2)
		sort_2(numbers);
	create_stack_a(a, numbers, numbers_size);
	free(numbers);
	if (numbers_size == 3)
	{
		sort_3(a, b);
		exit(0);
	}
	position_sort(a, b);
}
