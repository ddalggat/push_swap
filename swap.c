/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:57:47 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/01 22:10:16 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_struct **stack)
{
	t_struct	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return ;
}

void	swap_a(t_struct **stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
}
 
void	swap_b(t_struct **stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_struct **stack_a, t_struct **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}
