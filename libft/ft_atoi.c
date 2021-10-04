/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:20:46 by gjailbir          #+#    #+#             */
/*   Updated: 2021/09/28 18:41:13 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (1);
	return (0);
}

static	int	ft_ismax(long res)
{
	if (res > 2147483647)
		return (0);
	else if (res < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str, int *flag)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		if (!ft_ismax(res * sign))
		{
			*flag = 0;
			return (0);
		}
		str++;
	}
	return (res * sign);
}
