 	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:21:54 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/25 20:43:34 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_aux(char *s_str, char *apend)
{
	char 	*aux;

	if (!s_str && !apend)
		return (NULL);
	aux = ft_strjoin(s_str, apend);
	if (!aux)
		return (NULL);
	free(s_str);
	return (aux);
}

static char *ft_save_line(char *s_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if ())
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	j = ft_strchr(s_str, '\n') + 1;
	if (j > 0)
	{
		while (s_str[j + i] != '\0')
		{
			str[i] = s_str[j + i];
			i++;
		}
		str[i] = '\0';
	}
	return (free(s_str), str);
}

static char	*ft_return_line(char **s_str)
{
	int		i;
	char	*line;
	int		len;

	i = -1;
	if (*s_str == NULL)
		return (NULL);
	if (ft_strchr(*s_str, '\n') != -1)
		len = ft_strchr(*s_str, '\n') + 2;
	else
		len = ft_strlen(*s_str) + 1;
	line = (char *)malloc((sizeof(char) * len));
	if (!line)
		return (free(*s_str), NULL);
	while ((*s_str)[++i] != '\0' && (*s_str)[i] != '\n' && --len >= 0)
		line[i] = (*s_str)[i];
	if (ft_strchr(*s_str, '\n') != -1)
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
	{
		line[i] = '\0';
		free(*s_str);
		*s_str = NULL;
	}
	return (line);
}

static char	*ft_read_fd(int fd, char *s_str)
{
	int		len;
	char	*aux;

	aux = (char *)malloc(BUFFER_SIZE + 1);
	len = 1;
	while (len > 0)
	{
		len = read(fd, aux, BUFFER_SIZE);
		if(len < 0)
			return (free (aux), free (s_str), NULL);
		if (len == 0)
			break;
		aux[len] = '\0';
		s_str = ft_strjoin_aux(s_str, aux);
		if (ft_strchr(s_str, '\n') != -1)
			break;
	}
	free (aux);
	return (s_str);
}

char		*get_next_line(int fd)
{
	char			*line;
	static char		*s_str = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s_str = ft_read_fd(fd, s_str);
	if (s_str == NULL)
		return (NULL);
	line = ft_return_line(&s_str);
	if (s_str && ft_strchr(s_str, '\n') != -1)
		s_str = ft_save_line(s_str);
	return (line);
}	