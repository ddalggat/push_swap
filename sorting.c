/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:20:22 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 23:28:37 by gjailbir         ###   ########.fr       */
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
	while (len-- > 0 && i-- > 0)
	{
		if ((*stack_a)->bool == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
}

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

int maxx(int a, int b)
{
    if (a < b) return b;
    return a;
}
	
t_struct *ft_summation(t_struct **stack_b, t_max *max)
{
    int			buff[5];
    t_struct	*tmp_b;

    tmp_b = *stack_b;
    while (tmp_b)
    {
        buff[0] = maxx(tmp_b->ra, tmp_b->pair->ra);
        buff[1] = maxx(tmp_b->rra , tmp_b->pair->rra);
        buff[2] = tmp_b->pair->rra +  tmp_b->ra;
        buff[3] = tmp_b->pair->ra +tmp_b->rra;
        buff[4] = 0;
        int i = 1;
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
    tmp_b = *stack_b;
    max->min_steps = tmp_b->steps;
    t_struct	*tm = tmp_b;
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
    return tm;
}

void	ft_find_pair(t_struct **stack_a, t_struct **stack_b, t_max *max)
{
	t_struct	*tmp_a;
	t_struct	*tmp_b;
    t_struct    *tm;
	int			len;
	
	tmp_b = *stack_b;
	len = ft_lst_size(tmp_b);
	while (len-- > 0)
	{
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
	t_struct	*tmp;
    int         size;

	tmp = *stack_a;
	int i = 0;
	int index = 0;
	int minNum = tmp->num;
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
	i = index;
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