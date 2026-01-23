/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:32 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/23 19:47:29 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    send_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int     size;
    int     i;
    int     to_push;

    size = ft_lstsize(*stack_a);    
    int is_smaller = 1;
    int half = size / 2;
    to_push = size - 3;
    i = 0;
    while (i < size && to_push > 0) 
    {
        if (!((*stack_a)->index <= half) && is_smaller)
            rotate_x(stack_a, stack_a, 'a');
        push_x(stack_a, stack_b, 'b');
        to_push--;
        if (to_push == half - 3)
            is_smaller = 0;
        i++;
    }    
}