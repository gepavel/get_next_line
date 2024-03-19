/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/19 14:32:15 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
//	char			*str;
	char			*buffer;
//	static char		*s_str = NULL;
	
	buffer = (char *)malloc(1);
	if (!read(fd, buffer, BUFFER_SIZE))
		return (NULL);
	printf("BUFFER ES:%s\n", buffer);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	printf("el fd en open es:%d\n", fd);
	while (str = get_next_line(fd))
	{
		printf("[%s]", str);
		free(str);
	}
	close(fd);
	return (0);
}
