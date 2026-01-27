/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:18:15 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/19 19:21:42 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_biggest(t_stack *head)
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

t_stack *get_smallest(t_stack *head)
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