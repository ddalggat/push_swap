/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:59:20 by gjailbir          #+#    #+#             */
/*   Updated: 2021/09/30 22:26:36 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	push(t_struct **src, t_struct **dst)
{
	t_struct	*src_head;

	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	push_b(t_struct **stack_a, t_struct **stack_b)
{
	if (*stack_a)
		push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_a(t_struct **stack_b, t_struct **stack_a)
{
	if (*stack_b)
		push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
