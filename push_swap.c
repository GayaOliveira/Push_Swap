/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:53 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/24 20:03:25 by gmarinho         ###   ########.fr       */
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
        print_stack(a);  
        print_stack(b);  
        
        push_x(&a, &b, 'b');
        push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // push_x(&a, &b, 'b');
        // send_to_b(&a, &b);

        calculate_position(&a);
        calculate_position(&b);
        calculate_target_position(&a, &b);
        calculate_cost_b(&b);
        calculate_cost_a(&a, &b);
        
        print_stack(a);  
        print_stack(b);

                
        ft_lstclear(&a);
        ft_lstclear(&b);
                
    }   
    return (0);
}

/*
Será que na função calculate_cost_a, vale a pena adicionar alguma forma de 
checar se o custo deve ser positivo ou negativo para acompanhar cost_b?
*/