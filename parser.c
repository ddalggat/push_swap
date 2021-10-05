/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:32:25 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 22:48:36 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && str[i] != '+')
		i--;
	while (str[++i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_checker_stack(t_struct *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->num == num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_recording(t_struct **stack_a, char **buff, int i, int flag)
{
	int	num;

	while (buff[++i])
	{
		if (!ft_checker(buff[i]))
			return (0);
		num = ft_atoi(buff[i], &flag);
		if (num == 0 && flag == 0)
			return (0);
		if (!ft_checker_stack(*stack_a, num))
			return (0);
		ft_lst_add_back(stack_a, ft_lst_new(num));
		free(buff[i]);
	}
	return (1);
}

int	ft_parser(const char **arv, t_struct **stack_a)
{
	int		i;
	int		ind;
	int		res;
	int		flag;
	char	**buff;

	i = 0;
	ind = 0;
	flag = 1;
	while (arv[++ind])
	{
		buff = ft_split(arv[ind], ' ');
		if (!buff[0])
			return (0);
		i = -1;
		res = ft_recording(stack_a, buff, i, flag);
		if(!res)
			return (0);
		free(buff);
	}
	return (1);
}
