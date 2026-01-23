/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/23 19:50:46 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_position(t_stack **head)
{
    int i;
    t_stack *current;

    i = 0;
    current = *head;
    while (current)
    {        
        current->pos = i;
        i++;
        current = current->next;
    }    
}