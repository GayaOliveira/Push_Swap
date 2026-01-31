/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:32 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 16:42:20 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	to_push;
	int	is_smaller;
	int	half;

	size = ft_lstsize(*stack_a);
	is_smaller = 1;
	half = size / 2;
	to_push = size - 3;
	i = 0;
	while (i < size && to_push > 0)
	{
		while (!((*stack_a)->index <= half) && is_smaller)
			rotate_x(stack_a, stack_b, 'a');
		push_x(stack_a, stack_b, 'b');
		to_push--;
		if (to_push == size - half - 3)
			is_smaller = 0;
		i++;
	}
}
