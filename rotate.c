/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:53 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/31 18:41:39 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*second_node;
	t_stack	*last_node;

	second_node = (*head)->next;
	last_node = ft_lstlast(*head);
	second_node->prev = NULL;
	last_node->next = *head;
	(*head)->next = NULL;
	(*head)->prev = last_node;
	*head = second_node;
}

void	rotate_x(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		rotate(head_a);
		write(1, "ra\n", 3);
	}
	else if (stack == 'b')
	{
		rotate(head_b);
		write(1, "rb\n", 3);
	}
	else
	{
		rotate(head_a);
		rotate(head_b);
		write(1, "rr\n", 3);
	}
}
