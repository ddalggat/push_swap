/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:20:30 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/01 22:16:33 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_indexing(t_struct **stack_a)
{
	t_struct	*tmp;
	t_struct	*temp;
	int	count;

	tmp = *stack_a;
	while(tmp)
	{
		temp = *stack_a;
		tmp->bool = 0;
		count = 1;
		while(temp)
		{
			if (tmp->num > temp->num)
				count++;
			
			temp = temp->next;
		}
		tmp->index = count;
		tmp = tmp->next;
	}
}