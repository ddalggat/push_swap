/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:15:33 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 00:28:00 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ra(t_struct **stack_a)
{
	if (*stack_a)
		rotate(stack_a);
}

void	rb(t_struct **stack_b)
{
	if (*stack_b)
		rotate(stack_b);
}

void	rr(t_struct **stack_a, t_struct **stack_b)
{
	if (*stack_a)
		rotate(stack_a);
	if (*stack_b)
		rotate(stack_b);
}
