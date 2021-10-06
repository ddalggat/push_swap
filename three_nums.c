/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:39:09 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/06 20:43:11 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_sa(t_struct **stack_a)
{
	rev_a(stack_a);
	swap_a(stack_a);
}

void	ft_sa_rra(t_struct **stack_a)
{
	swap_a(stack_a);
	rev_a(stack_a);
}

void	ft_three_nums(t_struct **stack_a)
{
	t_struct	*tmp;

	tmp = *stack_a;
	ft_indexing(stack_a);
	if (tmp->index == 3 && tmp->next->index == 2
		&& tmp->next->next->index == 3)
		return ;
	else if (tmp->index == 1 && tmp->next->index == 3
		&& tmp->next->next->index == 2)
		ft_rra_sa(stack_a);
	else if (tmp->index == 2 && tmp->next->index == 1
		&& tmp->next->next->index == 3)
		swap_a(stack_a);
	else if (tmp->index == 2 && tmp->next->index == 3
		&& tmp->next->next->index == 1)
		rev_a(stack_a);
	else if (tmp->index == 3 && tmp->next->index == 1
		&& tmp->next->next->index == 2)
		rotate_a(stack_a);
	else if (tmp->index == 3 && tmp->next->index == 2
		&& tmp->next->next->index == 1)
		ft_sa_rra(stack_a);
	return ;
}
