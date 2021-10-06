/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:04:38 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 01:06:25 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted_list(t_struct **stack)
{
	t_struct	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_do_cmds(t_struct **stack_a, t_struct **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa", 100))
		sa(stack_a);
	else if (!ft_strncmp(line, "sb", 100))
		sb(stack_a);
	else if (!ft_strncmp(line, "ss", 100))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", 100))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb", 100))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra", 100))
		ra(stack_a);
	else if (!ft_strncmp(line, "rb", 100))
		rb(stack_a);
	else if (!ft_strncmp(line, "rr", 100))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra", 100))
		rra(stack_a);
	else if (!ft_strncmp(line, "rrb", 100))
		rrb(stack_a);
	else if (!ft_strncmp(line, "rrr", 100))
		rrr(stack_a, stack_b);
	else
		ft_putstr_fd("Error\n", 1);
}

void	ft_read_cmds(t_struct **stack_a, t_struct **stack_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_do_cmds(stack_a, stack_b, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, const char **argv)
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	int			res;

	if (argc == 1)
		exit(1);
	res = ft_parser(argv, &stack_a);
	if (!res)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	ft_read_cmds(&stack_a, &stack_b);
	res = ft_lst_size(stack_b);
	if (!issorted_list(&stack_a) && res == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
