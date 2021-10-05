/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:36:01 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/05 23:23:31 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int				num;
	int				index;
	int				greater_than;
	int 			bool;
	int				ra;
	int				rra;
	int				steps;
	int				ind_min_sum;
	struct s_struct	*pointer_to_step;
	struct s_struct	*pair;
	struct s_struct	*next;
}	t_struct;

typedef struct s_max
{
	int			max;
	int			min;
	int			min_steps;
	int			ind;
	int			temp;
	t_struct	*node;
}	t_max;

//***//parser_functions\\***//
t_struct	*ft_lst_last(t_struct	*lst);
t_struct	*ft_lst_new(int content);
void		ft_lst_add_back(t_struct **lst, t_struct *new);
void		ft_lst_add_front(t_struct **lst, t_struct *new);
int			ft_lst_size(t_struct *lst);
int			ft_parser(const char **arv, t_struct **stack_a);

//***//source_functions\\***//
int	ft_is_digit(char c);
int	ft_strcmp(char *str1, char *str2);

//***//swap_functions\\***//
void	swap_a(t_struct **stack_a);
void	swap_b(t_struct **stack_b);
void	swap_both(t_struct **stack_a, t_struct **stack_b);

//***//rotate_functions\\***//
void	rotate_a(t_struct **stack_a);
void	rotate_b(t_struct **stack_b);
void	rotate_both(t_struct **stack_a, t_struct **stack_b);

//***//reverse_functions\\***//
void	rev_a(t_struct **stack_a);
void	rev_b(t_struct **stack_b);
void	rev_both(t_struct **stack_a, t_struct **stack_b);

//***//push_functions\\***//
void	push_a(t_struct **stack_a, t_struct **stack_b);
void	push_b(t_struct **stack_b, t_struct **stack_a);

//***//push_back_functions\\***//
void	ft_rr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair);
void	ft_rrr(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair);
void	ft_rbrra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair);
void	ft_rrbra(t_struct **stack_b, t_struct **stack_a, t_struct *tmp_b, t_struct *tmp_pair);

//***//markind_functions\\***//
int		ft_remembering_end(t_struct *tmp, t_struct *temp, int ind);
void	ft_remembering_start(t_struct *tmp, t_struct *temp, int ind);
void	ft_marking(t_struct **stack_a);
void	ft_booling(t_struct *tmp, t_max *max, t_struct **stack_a);
void	ft_finding(t_struct **stack_a, t_max *max);

//***//main_functions\\***//
int		maxx(int a, int b);
void    ft_indexing(t_struct **stack_a);
void    ft_three_nums(t_struct **stack_a);
void	ft_push_to_b(t_struct **stack_a, t_struct **stack_b, t_max *max);
void	ft_steping(t_struct **stack);
void	ft_find_pair(t_struct **stack_a, t_struct **stack_b, t_max *max);
void	ft_sorting(t_struct **stack_a);

#endif
