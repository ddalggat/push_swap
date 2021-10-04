/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:53:58 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/04 20:47:57 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_max *max)
{
	while (tmp_b->ra > 0 || max->node->ra > 0)
	{
		if (tmp_b->ra > 0 && max->node->ra > 0)
			rotate_both(stack_a, stack_b);
		else if (tmp_b->ra > 0)
			rotate_b(stack_b);
		else if (max->node->ra > 0)
			rotate_a(stack_a);
		tmp_b->ra--;
		max->node->ra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rrr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_max *max)
{
	while (tmp_b->rra > 0 || max->node->rra > 0)
	{
		if (tmp_b->rra > 0 && max->node->rra > 0)
			rev_both(stack_a, stack_b);
		else if (tmp_b->rra > 0)
			rev_b(stack_b);
		else if (max->node->rra > 0)
			rev_a(stack_a);
		tmp_b->rra--;
		max->node->rra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rrbra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_max *max)
{
	while (tmp_b->rra > 0 || max->node->ra > 0)
	{
		if (tmp_b->rra > 0)
			rev_b(stack_b);
		else if (max->node->ra > 0)
			rotate_a(stack_a);
		tmp_b->rra--;
		max->node->ra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rbrra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_max *max)
{
	while (tmp_b->ra > 0 || max->node->rra > 0)
	{
		if (tmp_b->ra > 0)
			rotate_b(stack_b);
		else if (max->node->rra > 0)
			rev_a(stack_a);
		tmp_b->ra--;
		max->node->rra--;
	}
	push_a(stack_b, stack_a);
}
