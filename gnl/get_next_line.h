/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:30:33 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/07 05:31:50 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# include	<stdio.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_calloc_V2(int count);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);

#endif