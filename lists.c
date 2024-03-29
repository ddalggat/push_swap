/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:49:08 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 01:01:29 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lst_add_back(t_struct **lst, t_struct *new)
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

void	ft_lst_add_front(t_struct **lst, t_struct *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lst_size(t_struct *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}
