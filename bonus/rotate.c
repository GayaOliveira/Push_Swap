/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:53 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	}
	else if (stack == 'b')
	{
		rotate(head_b);
	}
	else
	{
		rotate(head_a);
		rotate(head_b);
	}
}
