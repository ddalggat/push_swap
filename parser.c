/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:32:25 by gjailbir          #+#    #+#             */
/*   Updated: 2021/09/21 19:06:59 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


t_struct	*ft_lst_last(t_struct	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_struct	*ft_lst_new(int content)
{
	t_struct	*list;

	list = malloc(sizeof(t_struct));
	if (!list)
		return (0);
	else
	{
		(*list).num = content;
		(*list).next = NULL;
		return (list);
	}
}


static void	ft_lst_add_back(t_struct **lst, t_struct *new)
{
	t_struct	*end;

	if (!*lst)
		*lst = new;
	else
	{
		end = ft_lst_last(*lst);
		end->next = new;
	}
}

int	ft_checker(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] != ' ' && !ft_is_digit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}


int	ft_parse(const char **str, t_struct **stack_a)
{
	int		i;
	int		ind;
	int		num;
	char	**buff;
	
	i = 0;
	ind = 1;
	while(str[ind])
	{
	   	buff = ft_split(str[ind], ' ');
		i = 0;
		while (buff[i])
		{
			if (!ft_checker(buff[i]))
				return (0);
			else
			{
				// printf("|%s|\n", buff[i]);
				num = ft_atoi(buff[i]);
				// printf("%d\n", num);
				ft_lst_add_back(stack_a, ft_lst_new(num));
			}
			i++;
		}
		ind++;
	}
	t_struct **tmp;
	tmp = stack_a;
	while ((*tmp))
	{
		printf("%d\n", (*tmp)->num);
		(*tmp) = (*tmp)->next;
	}
	
	return (1);
}



int main(int arc, const char **arv)
{
	(void)arc;
	int res;
	t_struct *stack_a;
	res = ft_parse(arv, &stack_a);
	printf("|%d|\n", res); 
}