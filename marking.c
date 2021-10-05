/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:09:30 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 23:21:30 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_remembering_end(t_struct *tmp, t_struct *temp, int ind)
{
	tmp->greater_than = 1;
	while (temp)
	{
		if (temp->index > ind)
		{
			tmp->greater_than++;
			ind = temp->index;
		}
		temp = temp->next;
	}
	return ind;
}

void	ft_remembering_start(t_struct *tmp, t_struct *temp, int ind)
{
	while (temp->index != tmp->index)
	{
		if (temp->index > ind)
		{
			tmp->greater_than++;
			ind = temp->index;
		}
		temp = temp->next;
	}
}

void	ft_marking(t_struct **stack_a)
{
	t_struct	*tmp;
	t_struct	*temp;
	int			ind;

	tmp = *stack_a;
	ft_indexing(stack_a);
	while (tmp)
	{
		temp = tmp->next;
		ind = tmp->index;
		ind = ft_remembering_end(tmp, temp, ind);
		temp = *stack_a;
		ft_remembering_start(tmp, *stack_a, ind);
		tmp = tmp->next;
	}
}

void	ft_booling(t_struct *tmp, t_max *max, t_struct **stack_a)
{
	int max_ind;
	
	tmp = max->node;
	max->temp = max->node->index;
	max_ind = max->node->greater_than;
	while (max_ind)
	{
		if (tmp->index >= max->temp)
		{
			max->temp = tmp->index;
			max_ind--;
			tmp->bool = 1;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = *stack_a;
	}
}

void	ft_finding(t_struct **stack_a, t_max *max)
{
	t_struct	*tmp;

	tmp = *stack_a;
	max->max = 0;
	ft_marking(stack_a);
	while (tmp)
	{
		if (max->max < tmp->greater_than)
		{
			max->max = tmp->greater_than;
			max->node = tmp;
		}
		tmp = tmp->next;
	}
	ft_booling(tmp, max, stack_a);
}
