/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:59:05 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/25 20:19:35 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (i);  
	while (str[i] != '\0')
		i++;
	return (i);	
}

int	ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] && s[i] != (char)c)
		i++;
	if (!c || s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;

	if (!s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;	
	}
	j = 0;
	while (s2[j] != '\0')	
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
