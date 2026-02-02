/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	swap(t_stack **head)
{
	t_stack	*second_node;
	t_stack	*third_node;

	second_node = (*head)->next;
	third_node = second_node->next;
	(*head)->next = third_node;
	(*head)->prev = second_node;
	third_node->prev = *head;
	second_node->next = *head;
	second_node->prev = NULL;
	*head = second_node;
}

void	swap_x(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		swap(head_a);
	}
	else if (stack == 'b')
	{
		swap(head_b);
	}
	else
	{
		swap(head_a);
		swap(head_b);
	}
}
