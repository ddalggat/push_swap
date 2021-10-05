/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:01:22 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 22:51:52 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_last_node(t_struct *lst)
{
	t_struct	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}

void	rotate(t_struct **stack)
{
	t_struct	*last;
	t_struct	*begin;

	begin = *stack;
	last = ft_last_node(begin);
	last->next = begin;
	*stack = begin->next;
	begin->next = NULL;
}

void	rotate_a(t_struct **stack_a)
{
	if (*stack_a)
		rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_struct **stack_b)
{
	if (*stack_b)
		rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_struct **stack_a, t_struct **stack_b)
{
	if (*stack_a)
		rotate(stack_a);
	if (*stack_b)
		rotate(stack_b);
	write(1, "rr\n", 3);
}
