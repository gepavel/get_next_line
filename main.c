/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/12 19:34:20 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char			*str;
	static char		buffer[256];
	static int		i;
	int				len;

	len = 0;
	if (!read(fd, buffer, 13))
		return (NULL);
	while (buffer[len] != '\n' && len < 13)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i  = 0;
	while (buffer[0] != '\n' && len-- > 0)
	{
		str[i] = buffer[0];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("text.txt", O_RDONLY);
	printf("el fd en open es:%d\n", fd);
	if (fd < 0)
		return (-1);
	for (i = 1; i <= 2; i++)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("1:[%s]\n", str);
		free (str);
	}
	close(fd);
	return (0);
}
