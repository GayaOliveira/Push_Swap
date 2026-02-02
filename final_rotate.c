/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:51:45 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:39 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **head_a, t_stack **head_b)
{
	int		size;
	t_stack	*smallest;
	int		i;

	size = ft_lstsize(*head_a);
	smallest = get_smallest(*head_a);
	calculate_position(head_a);
	i = 0;
	if (smallest->pos <= size / 2)
	{
		while (i < smallest->pos)
		{
			rotate_x(head_a, head_b, 'a');
			i++;
		}
	}
	else
	{
		while (i < size - smallest->pos)
		{
			reverse_rotate_x(head_a, head_b, 'a');
			i++;
		}
	}
}
