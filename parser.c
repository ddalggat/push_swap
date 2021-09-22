/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:32:25 by gjailbir          #+#    #+#             */
/*   Updated: 2021/09/22 20:48:41 by gjailbir         ###   ########.fr       */
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

int	ft_parser(const char **arv, t_struct **stack_a)
{
	int		i;
	int		ind;
	int		num;
	char	**buff;

	i = 0;
	ind = 0;
	while (arv[++ind])
	{
		buff = ft_split(arv[ind], ' ');
		i = -1;
		while (buff[++i])
		{
			if (!ft_checker(buff[i]))
				return (0);
			num = ft_atoi(buff[i]);
			if (!ft_checker_stack(*stack_a, num))
				return (0);
			ft_lst_add_back(stack_a, ft_lst_new(num));
			free(buff[i]);
		}
		free(buff);
	}
	return (1);
}
