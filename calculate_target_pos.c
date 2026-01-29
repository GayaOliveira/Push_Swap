/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/29 20:47:47 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(t_stack *head_a, t_stack *node)
{
	t_stack	*current;
	t_stack	*target;
	int		target_pos;

	current = head_a;
	target = get_biggest(head_a);
	target_pos = get_smallest(head_a)->pos;
	while (current)
	{
		if (current->index > node->index && current->index <= target->index)
		{
			target = current;
			target_pos = target->pos;
		}
		current = current->next;
	}
	return (target_pos);
}

void	calculate_target_position(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	current = *head_b;
	while (current)
	{
		current->target_pos = get_target_pos(*head_a, current);
		current = current->next;
	}
}
