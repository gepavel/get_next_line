/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/05/28 13:21:09 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i = 1;

	fd = open("text.txt", O_RDONLY);
	if (fd < 3)
		return (printf("wrong fd:%d\n", fd), 0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("vuelta:%d\n", i++);
		printf("[%s]\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
