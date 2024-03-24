/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:21:54 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/21 17:55:21 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strjoin_aux(char *s_str, char *apend)
{
	char 	*aux;

	aux = ft_strjoin(s_str, apend);
	if (!s_str)
		return (aux);
	free(s_str);
	return (aux);
}

static char *ft_save_line(char *s_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s_str)
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	j = ft_strchr(s_str, '\n');
	printf("j es;%d\n", j);
	while (s_str[j + i] != '\0')
	{
		str[i] = s_str[j + i];
		i++;
	}
	str[i] = '\0';
	return (free(s_str), str);
}

static char	*ft_return_line(char *s_str)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	len = ft_strchr(s_str, '\n');
	if (ft_strchr(s_str, '\n'))
	{
		line = (char *)malloc((sizeof(char) * len) + 2);
		if (!line)
			return (free(s_str), NULL);
		while (s_str[i] != '\n')
		{
			line[i] = s_str[i];
			i++;
		}
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else 
		return (s_str);
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
//		printf("len es:%d\n", len);
		if(len == 0)
			return (free (aux), free (s_str), NULL);
		aux[len] = '\0';
//		printf("aux es:%s\n", aux);
		s_str = ft_strjoin_aux(s_str, aux);
//		printf("s_str es:%s\n", s_str);
		if (ft_strchr(s_str, '\n') != 0)
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
	if (!s_str)
		return (NULL);
	line = ft_return_line(s_str);
	s_str = ft_save_line(s_str);
	return (line);
}