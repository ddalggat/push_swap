/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:23:46 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 23:34:49 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arc, const char **arv)
{
	int res;
	t_struct	*stack_a;
	t_struct	*stack_b;
	t_max		max;
	
	res = ft_parser(arv, &stack_a);
	if(!res)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (arc == 3)
	{
		if (stack_a->index > stack_a->next->index)
		swap_a(&stack_a);
	}
	else if (arc == 4)
		ft_three_nums(&stack_a);
	else if (arc > 4)
	{
		ft_push_to_b(&stack_a, &stack_b, &max);
		ft_find_pair(&stack_a, &stack_b, &max);
		ft_sorting(&stack_a);
	}
	return (0);
}