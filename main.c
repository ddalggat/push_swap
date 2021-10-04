/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:23:46 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/04 23:54:47 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_struct **stack_a, t_struct **stack_b)
{
	t_struct *tmp;
	t_struct *temp;
	tmp = *stack_a;
	temp = *stack_b;
	while(tmp)
	{
		printf("|num = %d|  |ind = %d|  |grt = %d| |bool = %d|  |ra = %d|  |rra = %d|\n", tmp->num, tmp->index, tmp->greater_than, tmp->bool, tmp->ra, tmp->rra);
		tmp = tmp->next;
	}
	printf("\n\n\n");
	while(temp)
	{
		printf("|num = %d|  |ind = %d|  |grt = %d| |bool = %d|  |ra = %d|  |rra = %d|\n", temp->num, temp->index, temp->greater_than, temp->bool, temp->ra, temp->rra);
		temp = temp->next;
	}
}

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
	// else if (arc > 4)
	// 	ft_more_than_four(&stack_a);
	ft_push_to_b(&stack_a, &stack_b, &max);
	ft_find_pair(&stack_a, &stack_b, &max);
	ft_print_stack(&stack_a, &stack_b);
	// printf("|max_grt = %d|", max_box.max_great);
	return (0);
}