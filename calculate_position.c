/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_position(t_stack **head)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *head;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}
