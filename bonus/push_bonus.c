/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:13:15 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 00:27:33 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_struct **src, t_struct **dst)
{
	t_struct	*src_head;

	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	pb(t_struct **stack_a, t_struct **stack_b)
{
	if (*stack_a)
		push(stack_a, stack_b);
}

void	pa(t_struct **stack_b, t_struct **stack_a)
{
	if (*stack_b)
		push(stack_b, stack_a);
}
