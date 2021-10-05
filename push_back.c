/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:53:58 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 23:19:53 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_rr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair)
{
	while (tmp_b->ra > 0 || tmp_pair->ra > 0)
	{
		if (tmp_b->ra > 0 && tmp_pair->ra > 0)
			rotate_both(stack_a, stack_b);
		else if (tmp_b->ra > 0)
			rotate_b(stack_b);
		else if (tmp_pair->ra > 0)
			rotate_a(stack_a);
		tmp_b->ra--;
		tmp_pair->ra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rrr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair)
{
	while (tmp_b->rra > 0 || tmp_pair->rra > 0)
	{
		if (tmp_b->rra > 0 && tmp_pair->rra > 0)
			rev_both(stack_a, stack_b);
		else if (tmp_b->rra > 0)
			rev_b(stack_b);
		else if (tmp_pair->rra > 0)
			rev_a(stack_a);
		tmp_b->rra--;
		tmp_pair->rra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rrbra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair)
{
	while (tmp_b->rra > 0 || tmp_pair->ra > 0)
	{
		if (tmp_b->rra > 0)
			rev_b(stack_b);
		if (tmp_pair->ra > 0)
			rotate_a(stack_a);
		tmp_b->rra--;
		tmp_pair->ra--;
	}
	push_a(stack_b, stack_a);
}

void	ft_rbrra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair)
{
	while (tmp_b->ra > 0 || tmp_pair->rra > 0)
	{
		if (tmp_b->ra > 0)
			rotate_b(stack_b);
		if (tmp_pair->rra > 0)
			rev_a(stack_a);
		tmp_b->ra--;
		tmp_pair->rra--;
	}
	push_a(stack_b, stack_a);
}
