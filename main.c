/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:10:14 by gepavel           #+#    #+#             */
/*   Updated: 2024/03/25 20:25:19 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		flag = 5;
	int		i = 1;

	fd = open("text.txt", O_RDONLY);
	if (fd < 1)
		return (printf("wrong fd:%d\n", fd), 0);
	while (flag-- > 0)
	{
		printf("vuelta:%d\n", i++);
		str = get_next_line(fd);
		if (str == NULL)
			return (free (str), 0);
		printf("[%s]\n", str);
	}
	close(fd);
	return (0);
}
