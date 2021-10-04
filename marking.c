/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:09:30 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/04 23:55:12 by gjailbir         ###   ########.fr       */
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

void	ft_push_to_b(t_struct **stack_a, t_struct **stack_b, t_max *max)
{
	t_struct	*tmp;
	int			len;

	tmp = *stack_a;
	len = ft_lst_size(tmp);
	ft_finding(stack_a, max);
	while (len-- > 0)
	{
		if ((*stack_a)->bool == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}

// ============================================================================ //

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

 void	ft_find_min(t_max *max, int *buff)
 {
	int	i;
	int	ind;

	i = 0; 
	while (buff[i])
	{
		ind = i;
		while (buff[ind])
		{
			if (buff[ind] < max->min)
			{
				max->min = buff[i];
				max->ind = ind;
			}
			ind++;
		}
		i++;
	}
 }

 void	ft_summation(t_struct *tmp_b, t_max *max)
 {
	int			buff[5];

	buff[0] = tmp_b->ra + max->node->ra;
	buff[1] = tmp_b->ra + max->node->rra;
	buff[2] = tmp_b->rra + max->node->ra;
	buff[3] = tmp_b->rra + max->node->rra;
	buff[4] = 0;
	max->min = buff[0];
	ft_find_min(max, buff);
 }

 void	ft_find_pair(t_struct **stack_a, t_struct **stack_b, t_max *max)
 {
	t_struct	*tmp_a;
	t_struct	*tmp_b;
	int			len;
	
	tmp_b = *stack_b;
	len = ft_lst_size(tmp_b);
	while (len-- > 0)
	{
		max->max = 2147483647;
		tmp_b = *stack_b;
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if ((tmp_a->index > tmp_b->index) && (tmp_a->index < max->max))
			{
				max->max = tmp_a->index;
				max->node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		ft_steping(stack_a);
		ft_steping(stack_b);
		ft_summation(tmp_b, max);
		if (max->ind == 0)
			ft_rr(stack_b, stack_a, tmp_b, max);
		else if (max->ind == 1)
			ft_rbrra(stack_b, stack_a, tmp_b, max);
		else if (max->ind == 2)
			ft_rrbra(stack_b, stack_a, tmp_b, max);
		else if (max->ind == 3)
			ft_rrr(stack_b, stack_a, tmp_b, max);
	}
}
