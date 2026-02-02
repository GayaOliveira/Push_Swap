/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:39 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost_b(t_stack **head)
{
	int		i;
	float	half;
	t_stack	*current;

	i = 0;
	half = (float)ft_lstsize(*head) / 2;
	current = *head;
	while (current)
	{
		if (current->pos <= half)
		{
			current->cost_b = i;
			if (!(current->pos == half))
				i++;
		}
		else
		{
			i--;
			current->cost_b = -i;
		}
		current = current->next;
	}
}

static int	get_cost_a(t_stack **head_a, int target_pos)
{
	float	half;

	half = (float)ft_lstsize(*head_a) / 2;
	if (target_pos <= half)
		return (target_pos);
	return (target_pos - ft_lstsize(*head_a));
}

void	calculate_cost_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	current = *head_b;
	while (current)
	{
		current->cost_a = get_cost_a(head_a, current->target_pos);
		current = current->next;
	}
}
