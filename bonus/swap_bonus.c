/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:16:23 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 00:27:39 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sa(t_struct **stack_a)
{
	swap_stack(stack_a);
}

void	sb(t_struct **stack_b)
{
	swap_stack(stack_b);
}

void	ss(t_struct **stack_a, t_struct **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
