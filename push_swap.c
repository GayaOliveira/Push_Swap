/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:53 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/26 21:05:35 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack *stack)
{
    t_stack *temp;
    
    temp = stack;
    while (temp)
    {
        printf("%d (%p) - prev %p - next %p - pos %d - tp %d - ca %d - cb %d\n",
            temp->value, temp, temp->prev, temp->next, temp->pos, temp->target_pos, temp->cost_a, temp->cost_b);
        temp = temp->next;
    }
    printf("\n");
}

void    print_node(t_stack *node)
{
    printf("%d - ca %d - cb %d\n", node->value, node->cost_a, node->cost_b);    
    printf("\n");
}

void    move_both(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{      
    while (*cost_a > 0 && *cost_b > 0)
    {         
        rotate_x(head_a, head_b, 'r');
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        reverse_rotate_x(head_a, head_b, 'r');
        (*cost_a)++;
        (*cost_b)++;
    }
}

void    move_one(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0)
    {
        rotate_x(head_a, head_b, 'a');
        (*cost_a)--;
    }
    while (*cost_a < 0)
    {
        reverse_rotate_x(head_a, head_b, 'a');
        (*cost_a)++;
    }
    while (*cost_b > 0)
    {
        rotate_x(head_a, head_b, 'b');
        (*cost_b)--;
    }
    while (*cost_b < 0)
    {
        reverse_rotate_x(head_a, head_b, 'b');
        (*cost_b)++;
    }
}

void    move_current_node(t_stack **head_a, t_stack **head_b, t_stack *node)
{
        int cost_a;
        int cost_b;
        
        cost_a = node->cost_a;
        cost_b = node->cost_b;
        move_both(head_a, head_b, &cost_a, &cost_b);
        move_one(head_a, head_b, &cost_a, &cost_b);        
        push_x(head_a, head_b, 'a');       
}

void position_sort(t_stack **head_a, t_stack **head_b)
{
    while (ft_lstsize(*head_b))
    {
        calculate_position(head_a);
        calculate_position(head_b);
        calculate_target_position(head_a, head_b);
        calculate_cost_a(head_a, head_b);
        calculate_cost_b(head_b);
        move_current_node(head_a, head_b, choose_node_to_move(*head_b));
    }
}

void final_rotate(t_stack **head_a, t_stack **head_b)
{
    int size;
    t_stack *smallest;
    int i;

    size = ft_lstsize(*head_a);
    smallest = get_smallest(*head_a);
    calculate_position(head_a);
    i = 0;
    if (smallest->pos <= size / 2)
    {
        while (i < smallest->pos)
        {
            rotate_x(head_a, head_b, 'a');
            i++;
        }        
    }
    else
    {
        while (i < size - smallest->pos)
        {
            reverse_rotate_x(head_a, head_b, 'a');
            i++;
        } 
    }
}

int main(int argc, char **argv)
{
    char **treated_entry;
    int *numbers;
    int numbers_size;
    int *indexes;
    t_stack *a;
    t_stack *b;
    
    if (argc >= 2)
    {        
        treated_entry = prepare_to_convert(argv, argc - 1);
        numbers_size = arraylen(treated_entry);  
        if (!is_convertible(treated_entry, numbers_size))
            return (show_error(treated_entry));
        numbers = parse_to_int(treated_entry, numbers_size);
        if (!numbers)
            return (show_error(treated_entry));
        if (is_duplicate(numbers, numbers_size))
        {
            write(2, "Error\n", 6);
            free(numbers);
            return (1);
        }
        if (numbers_size == 0 || numbers_size == 1)
        {
            free(numbers);
            return (0);
        }       
        if (numbers_size == 2)
        {
            if (numbers[0] > numbers[1])
                write(1, "sa\n", 3);
            free(numbers);
            return (0);            
        }        
        indexes = get_index(numbers, numbers_size);            
        a = NULL;
        b = NULL;
        create_stack_a(&a, numbers, indexes, numbers_size);
        free(numbers);
        free(indexes);
        if (numbers_size == 3)
        {
            sort_3(&a, &b);
            return (0);            
        }

        send_to_b(&a, &b);
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');

        // printf("%d\n", get_target_pos(&a, &b));
         
                      
        // print_node(choose_node_to_move(b));
        // move_current_node(&a, &b, choose_node_to_move(b));
        
        position_sort(&a, &b);

        final_rotate(&a, &b);

        // print_stack(a);
        // print_stack(b);
                
        // ft_lstclear(&a);
        // ft_lstclear(&b);
                
    }   
    return (0);
}
