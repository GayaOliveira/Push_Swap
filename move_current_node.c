/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_current_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:04 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:39 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both(t_stack **head_a, t_stack **head_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_x(head_a, head_b, 'r');
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_x(head_a, head_b, 'r');
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	move_one(t_stack **head_a, t_stack **head_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0)
	{
		rotate_x(head_a, head_b, 'a');
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		reverse_rotate_x(head_a, head_b, 'a');
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		rotate_x(head_a, head_b, 'b');
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		reverse_rotate_x(head_a, head_b, 'b');
		(*cost_b)++;
	}
}

void	move_current_node(t_stack **head_a, t_stack **head_b, t_stack *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	move_both(head_a, head_b, &cost_a, &cost_b);
	move_one(head_a, head_b, &cost_a, &cost_b);
	push_x(head_a, head_b, 'a');
}
