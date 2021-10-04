/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:39:09 by gjailbir          #+#    #+#             */
/*   Updated: 2021/09/28 15:06:30 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_three_nums(t_struct **stack_a)
{
    t_struct    *tmp;
    
    tmp = *stack_a;
    if (tmp->index == 3 && tmp->next->index == 2 && tmp->next->next->index == 3)
        return ;
    else if (tmp->index == 1 && tmp->next->index == 3 && tmp->next->next->index == 2)
    {
        rev_a(stack_a);
        swap_a(stack_a);
    }
    else if (tmp->index == 2 && tmp->next->index == 1 && tmp->next->next->index == 3)
        swap_a(stack_a);
    else if (tmp->index == 2 && tmp->next->index == 3 && tmp->next->next->index == 1)
        rev_a(stack_a);
    else if (tmp->index == 3 && tmp->next->index == 1 && tmp->next->next->index == 2)
        rotate_a(stack_a);
    else if (tmp->index == 3 && tmp->next->index == 2 && tmp->next->next->index == 1)
        {
            swap_a(stack_a);
            rev_a(stack_a);
        }
    return ;
}