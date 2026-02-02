/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:57:55 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:39 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_sort(t_stack **head_a, t_stack **head_b)
{
	send_to_b(head_a, head_b);
	sort_3(head_a, head_b);
	while (ft_lstsize(*head_b))
	{
		calculate_position(head_a);
		calculate_position(head_b);
		calculate_target_position(head_a, head_b);
		calculate_cost_a(head_a, head_b);
		calculate_cost_b(head_b);
		move_current_node(head_a, head_b, choose_node_to_move(*head_b));
	}
	final_rotate(head_a, head_b);
}
