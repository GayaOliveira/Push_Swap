/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:17:52 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/21 19:08:10 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_abs(int nbr)
{
    if (nbr < 0)
        nbr = -nbr;
    return (nbr);
}

static int get_total_cost(t_stack *current)
{
	int cost_a;
    	int cost_b;
    
	cost_a = current->cost_a;
	cost_b = current->cost_b;
	if((cost_a >= 0 && cost_b < 0) || (cost_a < 0 && cost_b >= 0))
		return (ft_abs(cost_a) + ft_abs(cost_b));
	if (ft_abs(cost_a) > ft_abs(cost_b))
		return(ft_abs(cost_a));
	return(ft_abs(cost_b));	
}

t_stack *choose_node_to_move(t_stack *head_b)
{
    t_stack *to_push;
    t_stack *current;
    int lowest_total_cost;
    int total_cost;

    to_push = head_b;
    current = head_b;
    lowest_total_cost = ft_lstsize(head_b);
    while (current)
    {
        total_cost = get_total_cost(current);
        if (lowest_total_cost > total_cost)
        {
            lowest_total_cost = total_cost;
            to_push = current;
        }            
        current = current->next;
    }
    return (to_push);      
}