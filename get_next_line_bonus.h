/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:23:50 by gepavel           #+#    #+#             */
/*   Updated: 2024/05/28 15:05:10 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif	

# include <stdlib.h>
# include <fcntl.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_dup(char *s1, char *s2);
int		ft_strchr_pos(char *s, int c);
int		ft_strlen(char *str);

#endif
