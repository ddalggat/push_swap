/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:09:46 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 00:27:53 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct	*penultimate_node(t_struct *lst)
{
	t_struct	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next->next)
		tmp = tmp -> next;
	return (tmp);
}

void	reverse(t_struct **stack)
{
	t_struct	*tmp;
	t_struct	*begin;

	begin = *stack;
	tmp = penultimate_node(*stack);
	tmp->next->next = begin;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	rra(t_struct **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		reverse(stack_a);
}

void	rrb(t_struct **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		reverse(stack_b);
}

void	rrr(t_struct **stack_a, t_struct **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		reverse(stack_b);
	if (*stack_a && (*stack_a)->next)
		reverse(stack_a);
}
