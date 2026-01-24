/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/24 18:25:58 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *get_biggest(t_stack *head)
{
    t_stack *biggest;
    t_stack *current;

    current = head;
    biggest = current;
    while (current)
    {
        if (current->index > biggest->index)
            biggest = current;
        current = current->next;
    }
    return (biggest);
}

static t_stack *get_smallest(t_stack *head)
{
    t_stack *smallest;
    t_stack *current;

    current = head;
    smallest = current;
    while (current)
    {
        if (current->index < smallest->index)
            smallest = current;
        current = current->next;
    }
    return (smallest);
}

static int get_target_pos(t_stack *head_a, t_stack *node)
{
    t_stack *current;
    t_stack *target;
    int     target_pos;
    

    current = head_a;
    target = get_biggest(head_a);
    target_pos = get_smallest(head_a)->pos;
    while (current)
    {
        if (current->index > node->index && current->index < target->index)
        {
            target = current;
            target_pos = target->pos;
        }
        current = current->next;
    }
    return (target_pos);
}

void calculate_target_position(t_stack **head_a, t_stack **head_b)
{
    t_stack *current;

    current = *head_b;
    while (current)
    {        
        current->target_pos = get_target_pos(*head_a, current);
        current = current->next;
    }    
}