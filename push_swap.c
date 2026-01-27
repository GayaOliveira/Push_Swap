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

int abs(int nbr)
{
    if (nbr < 0)
        nbr = -nbr;
    return (nbr);
}

int get_total_cost(t_stack *current)
{
    int total_cost;

    if ((current->cost_a >= 0 && current->cost_b < 0) 
        || (current->cost_a < 0 && current->cost_b >= 0))
            total_cost = abs(current->cost_a) + abs(current->cost_b);
    if (current->cost_a >= 0 && current->cost_b >= 0)
    {
        if (current->cost_a > current->cost_b)
            total_cost = current->cost_a;
        else
            total_cost = current->cost_b;
    }
    if (current->cost_a < 0 && current->cost_b < 0)
    {
        if (current->cost_a < current->cost_b)
            total_cost = current->cost_a;
        else
            total_cost = current->cost_b;
    }
    return (total_cost);
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

void    move_current_node(t_stack **head_a, t_stack **head_b, t_stack *node)
{
        int cost_a;
        int cost_b;
        int i;
        
        cost_a = node->cost_a;
        cost_b = node->cost_b;
        i = 0;

        while (cost_a > 0 && cost_b > 0)
        {         
            rotate_x(head_a, head_b, 'r');
            cost_a--;
            cost_b--;
        }
        while (cost_a < 0 && cost_b < 0)
        {
            reverse_rotate_x(head_a, head_b, 'r');
            cost_a++;
            cost_b++;
        }
        while (cost_a > 0)
        {
            rotate_x(head_a, head_b, 'a');
            cost_a--;
        }
        while (cost_a < 0)
        {
            reverse_rotate_x(head_a, head_b, 'a');
            cost_a++;
        }
        while (cost_b > 0)
        {
            rotate_x(head_a, head_b, 'b');
            cost_b--;
        }
        while (cost_b < 0)
        {
            reverse_rotate_x(head_a, head_b, 'b');
            cost_b++;
        }
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
        
        // swap_x(&a, &b, 'a');
        // rotate_x(&a, &b, 'a');
        // reverse_rotate_x(&a, &b, 'a');
        // push_x(&a, &b, 'b');
        // calculate_position(&a);
        
        push_x(&a, &b, 'b');
        push_x(&a, &b, 'b');
        push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        send_to_b(&a, &b);

                
        // print_stack(a);  
        // print_stack(b);
      
        // print_node(choose_node_to_move(b));
        // move_current_node(&a, &b, choose_node_to_move(b));
        
        position_sort(&a, &b);

        

        // print_stack(a);  
        // print_stack(b);
                
        ft_lstclear(&a);
        ft_lstclear(&b);
                
    }   
    return (0);
}
