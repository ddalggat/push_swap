/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:53:56 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/06 22:54:54 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_steping(t_struct **stack)
{
	t_struct	*tmp;
	int			len;
	int			length;

	tmp = *stack;
	length = ft_lst_size(tmp);
	len = length;
	tmp = *stack;
	while (len)
	{
		tmp->ra = length - len;
		tmp->rra = len;
		tmp = tmp->next;
		len--;
	}
}

void	ft_find_min(t_max *max, int *buff, t_struct *tmp_b)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] < max->min)
		{
			max->min = buff[i];
			tmp_b->ind_min_sum = i;
		}
		i++;
	}
	tmp_b->steps = max->min;
}

void	ft_min_step(t_struct **stack_b, int *buff)
{
	t_struct	*tmp_b;
	int			i;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		buff[0] = maxx(tmp_b->ra, tmp_b->pair->ra);
		buff[1] = maxx(tmp_b->rra, tmp_b->pair->rra);
		buff[2] = tmp_b->pair->rra + tmp_b->ra;
		buff[3] = tmp_b->pair->ra + tmp_b->rra;
		buff[4] = 0;
		i = 1;
		tmp_b->steps = buff[0];
		tmp_b->ind_min_sum = 0;
		while (i < 4)
		{
			if (buff[i] < tmp_b->steps)
			{
				tmp_b->steps = buff[i];
				tmp_b->ind_min_sum = i;
			}
			i++;
		}
		tmp_b = tmp_b->next;
	}
}

t_struct	*ft_summation(t_struct **stack_b, t_max *max)
{
	int			buff[5];
	t_struct	*tmp_b;
	t_struct	*tm;

	ft_min_step(stack_b, buff);
	tmp_b = *stack_b;
	max->min_steps = tmp_b->steps;
	tm = tmp_b;
	while (tmp_b)
	{
		if (tmp_b->steps < max->min_steps)
		{
			max->min_steps = tmp_b->steps;
			tm = tmp_b;
			tm->ind_min_sum = tmp_b->ind_min_sum;
		}
		tmp_b = tmp_b->next;
	}
	return (tm);
}
