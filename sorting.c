/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:20:22 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/06 22:57:39 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_struct **stack_a, t_struct **stack_b, t_max *max)
{
	t_struct	*tmp;
	int			len;
	int			i;

	tmp = *stack_a;
	len = ft_lst_size(tmp);
	ft_finding(stack_a, max);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->bool == 0)
			i++;
		tmp = tmp->next;
	}
	while (len-- > 0 && i > 0)
	{
		if ((*stack_a)->bool == 0)
		{
			push_b(stack_a, stack_b);
			i--;
		}
		else
			rotate_a(stack_a);
	}
}

void	ft_push_pair(t_struct **stack_a, t_struct **stack_b, t_max *max)
{
	t_struct	*tmp_b;
	t_struct	*tm;
	int			len;

	tmp_b = *stack_b;
	len = ft_lst_size(tmp_b);
	while (len-- > 0)
	{
		ft_find_pair(stack_b, stack_a, max);
		tmp_b = *stack_b;
		ft_steping(stack_a);
		ft_steping(stack_b);
		tm = ft_summation(stack_b, max);
		if (tm->ind_min_sum == 0)
			ft_rr(stack_b, stack_a, tm, tm->pair);
		else if (tm->ind_min_sum == 1)
			ft_rrr(stack_b, stack_a, tm, tm->pair);
		else if (tm->ind_min_sum == 2)
			ft_rbrra(stack_b, stack_a, tm, tm->pair);
		else if (tm->ind_min_sum == 3)
			ft_rrbra(stack_b, stack_a, tm, tm->pair);
		tmp_b = tmp_b->next;
	}
}

void	ft_sorting(t_struct **stack_a)
{
	int			size;
	int			i;

	i = ft_min_num(stack_a);
	size = ft_lst_size(*stack_a);
	if (size / 2 > i)
		while (i-- > 0)
			rotate_a(stack_a);
	else
	{
		size -= i;
		while (size-- > 0)
			rev_a(stack_a);
	}
}
