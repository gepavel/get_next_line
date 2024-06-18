/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:21:54 by gepavel           #+#    #+#             */
/*   Updated: 2024/05/28 15:07:30 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin_aux(char **str, char *apend)
{
	char	*aux;

	if (!(*str) && !apend)
		return (NULL);
	aux = ft_strjoin_dup(*str, apend);
	return (free(*str), aux);
}

static char	*ft_save_line(char **s_str)
{
	char	*str;
	int		nl_pos;

	nl_pos = ft_strchr_pos(*s_str, '\n');
	if (nl_pos + 1 == ft_strlen(*s_str))
		return (free(*s_str), *s_str = NULL, NULL);
	str = ft_strjoin_dup(NULL, &(s_str[0][nl_pos + 1]));
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
		return (line);
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

	aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!aux)
		return (free (*s_str), *s_str = NULL, NULL);
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
	free(aux);
	return (*s_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s_str[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s_str[fd] = ft_read_fd(fd, &s_str[fd]);
	if (s_str[fd] == NULL)
		return (NULL);
	line = ft_return_line(&s_str[fd]);
	if (s_str[fd] != NULL && ft_strchr_pos(s_str[fd], '\n') != -1)
		s_str[fd] = ft_save_line(&s_str[fd]);
	else
	{
		free (s_str[fd]);
		s_str[fd] = NULL;
	}
	return (line);
}
