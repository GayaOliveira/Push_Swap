/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/29 20:47:47 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **src, t_stack **dest)
{
	int	first;
	int	second;
	int	third;

	first = (*src)->value;
	second = ((*src)->next)->value;
	third = (((*src)->next)->next)->value;
	if (first > second && first > third)
	{
		rotate_x(src, dest, 'a');
		if (second > third)
			swap_x(src, dest, 'a');
	}
	else if (second > first && second > third)
	{
		reverse_rotate_x(src, dest, 'a');
		if (third > first)
			swap_x(src, dest, 'a');
	}
	if (third > first && third > second)
	{
		if (first > second)
			swap_x(src, dest, 'a');
	}
}
