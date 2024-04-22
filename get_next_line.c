/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:21:54 by gepavel           #+#    #+#             */
/*   Updated: 2024/04/18 13:29:16 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_aux(char **str, char *apend)
{
	char	*aux;

	if (!(*str) && !apend)
		return (NULL);
	aux = ft_strjoin_dup(*str, apend);
	return (free(*str), *str = NULL, aux);
}

static char	*ft_save_line(char **s_str)
{
	char	*str;

	if (ft_strchr_pos(*s_str, '\n') + 1 == ft_strlen(*s_str))
		return (free(*s_str), *s_str = NULL, NULL);
	str = ft_strjoin_pos(NULL, &(s_str[0][ft_strchr_pos(*s_str, '\n') + 1]));
	return (free(*s_str), *s_str = NULL, str);
}

static char	*ft_return_line(char **s_str)
{
	int		i;
	char	*line;
	int		len;

	i = -1;
	if (ft_strchr_pos(*s_str, '\n') != -1)
		len = ft_strchr_pos(*s_str, '\n') + 2;
	else
	{
		line = ft_strjoin_dup(NULL, *s_str);
		return (free(*s_str), *s_str = NULL, line);
	}
	line = (char *)malloc((sizeof(char) * len));
	if (!line)
		return (free(*s_str), *s_str = NULL, NULL);
	while ((*s_str)[++i] != '\0' && (*s_str)[i] != '\n' && --len >= 0)
		line[i] = (*s_str)[i];
	if (ft_strchr_pos(*s_str, '\n') != -1)
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	return (line);
}

static char	*ft_read_fd(int fd, char **s_str)
{
	int		len;
	char	*aux;

	aux = (char *)malloc(BUFFER_SIZE + 1);
	len = 1;
	while (len > 0)
	{
		len = read(fd, aux, BUFFER_SIZE);
		if (len < 0)
			return (free (aux), free (*s_str), *s_str = NULL, NULL);
		if (len == 0)
			break ;
		aux[len] = '\0';
		*s_str = ft_strjoin_aux(s_str, aux);
		if (ft_strchr_pos(*s_str, '\n') != -1)
			break ;
	}
	free (aux);
	return (*s_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s_str = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s_str = ft_read_fd(fd, &s_str);
	if (s_str == NULL)
		return (NULL);
	line = ft_return_line(&s_str);
	if (s_str && ft_strchr_pos(s_str, '\n') != -1)
		s_str = ft_save_line(&s_str);
	else
	{
		free (s_str);
		s_str = NULL;
	}
	return (line);
}
