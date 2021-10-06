/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:05:22 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/06 22:52:01 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_min_num(t_struct **stack_a)
{
	t_struct	*tmp;
	int			minNum;
	int			index;
	int			i;

	i = 0;
	index = 0;
	tmp = *stack_a;
	minNum = tmp->num;
	while (tmp)
	{
		if (tmp->num < minNum)
		{
			minNum = tmp->num;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	ft_find_pair(t_struct **stack_b, t_struct **stack_a, t_max *max)
{
	t_struct	*tmp_b;
	t_struct	*tmp_a;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		max->max = 2147483647;
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if ((tmp_a->index > tmp_b->index) && (tmp_a->index < max->max))
			{
				max->max = tmp_a->index;
				tmp_b->pair = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

int	maxx(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
