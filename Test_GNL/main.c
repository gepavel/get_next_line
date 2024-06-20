/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/06/20 13:39:54 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	//int		i = 1;

	fd = open("text1.txt", O_RDONLY);
	/*if (fd < 3)
		return (printf("wrong fd:%d\n", fd), 0);
	str = get_next_line(0);*/
	while ((str = get_next_line(fd)))
	{	
		//printf("vuelta:%d\n", i++);
		printf("%s", str);
		free(str);
		//str = get_next_line(fd);
	}
	close(fd);
	return (0);
}



/*int	main(void)
{
	int		fd;
	char	*str;
	int		i = 1;

	fd = 2;

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
}*/


